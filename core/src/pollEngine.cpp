#include "pollEngine.hpp"

#include <sys/epoll.h>

#include <cstring>
#include <iostream>

#include "adapter.hpp"
#include "app.hpp"
#include "common.hpp"

#include <memory>

namespace {

    constexpr auto INFINITE_TIME = (-1);

    int setUpEpoll() {
        int epoll_fd = epoll_create1(0);
        if (epoll_fd == -1) {
            perror("epoll_create1 failed!");
            return common::FAILURE;
        }
        return epoll_fd;
    }

    int getEventType(const common::HandleInfo& handle) {
        if (handle.m_type == common::TCP_SERVER) {
            return EPOLLIN;
        }
        if (handle.m_type == common::TCP_CLIENT) {
            return EPOLLIN | EPOLLOUT;
        }
        std::cout << "Only TCP Server Or TCP Client connections are supported!"
                  << std::endl;
        return 0;
    }

    void processEvent(const app::UserObj* entity, epoll_event& event) {
        if (entity == nullptr) return;
        auto& adapter = entity->getAdapter();

        if (adapter.m_callbacks.find(event.data.fd) !=
            adapter.m_callbacks.end()) {
            adapter.m_callbacks.at(event.data.fd)(event.data.fd);
        }
    }

}  // namespace

namespace core {

    int eventLoop(const app::UserObj* entity) {
        int epoll_fd = setUpEpoll();

        if (epoll_fd == -1) {
            std::cout << "Framework could not create Epoll FD!" << std::endl;
            return common::FAILURE;
        }

        auto adapter = entity->getAdapter();

        for (auto&& handle : adapter.m_handles) {
            struct epoll_event event{};
            memset(&event, 0, sizeof(event));

            event.events = EPOLLIN;  // getEventType(handle);
            event.data.fd = handle.m_fd;

            if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, handle.m_fd, &event)) {
                std::cout << "Framework Failed to add App fd to Epoll watch!"
                          << std::endl;
                close(epoll_fd);
                return common::FAILURE;
            }
            std::cout << "Added fd = " << handle.m_fd << std::endl;
        }

        int maxEvents =
            10;  // this needs to be configurable by the user or internally
                 // TODO: deka fix this

        auto events = std::make_unique<epoll_event[]>(maxEvents);

        if (events == nullptr) {
            std::cout << "Memory allocation for epoll events failed!"
                      << std::endl;
            return common::FAILURE;
        }
    
        while (true) {
            int eventCount = 0;
            eventCount = epoll_wait(epoll_fd, events.get(), maxEvents, INFINITE_TIME);
            if (eventCount == -1) {
                std::cout << "Epoll could not wait and failed !" << std::endl;
                return common::FAILURE;
            }
            std::cout << eventCount << " events processing ..." << std::endl;
            for (int i = 0; i < eventCount; i++) {
                epoll_event& event = events[i];
                std::cout << "Now processing fd = " << event.data.fd
                          << std::endl;
                processEvent(entity, event);
            }
        }
    }
}  // namespace core