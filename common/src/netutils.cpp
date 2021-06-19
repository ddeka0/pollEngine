#include "netutils.hpp"

#include <cerrno>
#include <fcntl.h>

#include <cstring>
#include <iostream>

#include "common.hpp"

namespace utils {

    auto setNonBlock(int fd) -> int {
        int flags;
        if ((flags = fcntl(fd, F_GETFL, 0)) == -1) {
            printf("fcntl get flags failed on fd %d, Error %s", fd,
                   strerror(errno));
            return common::FAILURE;
        }

        if (fcntl(fd, F_SETFL, flags | O_NONBLOCK) == -1) {
            printf("fcntl set flags failed on fd %d, Error %s", fd,
                   strerror(errno));
            return common::FAILURE;
        }
        return common::SUCCESS;
    }

    auto createTcpServerSocket(const std::string& addr, int port,
                              common::HandleInfo& handle) -> int {
        int server_fd;
        struct sockaddr_in address{};
        int opt = 1;
        int addrlen = sizeof(address);

        if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
            perror("socket failed");
            return common::FAILURE;
        }

        if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt,
                       sizeof(opt)) != 0) {
            perror("setsockopt");
            return common::FAILURE;
        }

        address.sin_family = AF_INET;
        address.sin_addr.s_addr = inet_addr(addr.c_str());
        address.sin_port = htons(port);

        if (bind(server_fd, reinterpret_cast<struct sockaddr*>(&address), sizeof(address)) < 0) {
            perror("bind failed");
            return common::FAILURE;
        }

        if (setNonBlock(server_fd) != 0) {
            std::cout << "Could not make the server tcp socket non blocking!"
                      << std::endl;
            return common::FAILURE;
        }

        listen(server_fd, 10);  // argument or config params

        handle.m_fd = server_fd;
        handle.m_name = "tcp_sever";
        handle.m_type = common::TCP_SERVER;

        return common::SUCCESS;
    }
}  // namespace utils