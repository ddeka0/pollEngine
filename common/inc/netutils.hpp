#ifndef _HOME_DEKA_ACADEMIC_POLLENGINE_COMMON_INC_NETUTILS_HPP
#define _HOME_DEKA_ACADEMIC_POLLENGINE_COMMON_INC_NETUTILS_HPP

#pragma once
#include <string>

namespace common {
    class HandleInfo;
} // namespace common

namespace utils {
    auto setNonBlock(int fd) -> int;
    auto createTcpServerSocket(const std::string& addr, int port,
                              common::HandleInfo& handle) -> int;
}  // namespace utils
#endif
