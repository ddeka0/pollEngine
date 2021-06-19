#include "adapter.hpp"

#include <iostream>

#include "app.hpp"
#include "netutils.hpp"

namespace {
    auto acceptCallBack(int fd) -> int {
        std::cout << "acceptCallBack called!" << std::endl;
        char buf[100];
        read(fd, buf, 10);

        return common::SUCCESS;
    }
}  // namespace

namespace adapter {

    Adapter::Adapter(app::UserObj* entity) {
        this->entity = entity;
        std::cout << "Adapter is created!" << std::endl;
    }

    void Adapter::addHandle(common::HandleInfo&& handleInfo) {
        m_callbacks[handleInfo.m_fd] = acceptCallBack;  // function pointer
        m_handles.push_back(std::move(handleInfo));
    }
    auto Adapter::configure(int flags) -> int {
        if ((flags & common::TCP_SERVER) != 0) {
            common::HandleInfo handle;
            int server_fd =
                utils::createTcpServerSocket(server_addr, server_port, handle);
            if (server_fd == -1) {
                std::cout << "Problem in creating TCP server socket!"
                          << std::endl;
                return common::FAILURE;
            }
            addHandle(std::move(handle));
            return common::SUCCESS;
        }
        std::cout << "Only TCP_SERVER is supported as of now!" << std::endl;
        return common::FAILURE;
    }
}  // namespace adapter