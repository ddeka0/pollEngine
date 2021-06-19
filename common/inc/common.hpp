#ifndef _HOME_DEKA_ACADEMIC_POLLENGINE_COMMON_INC_COMMON_HPP
#define _HOME_DEKA_ACADEMIC_POLLENGINE_COMMON_INC_COMMON_HPP

#pragma once
#include <arpa/inet.h>
#include <cstdlib>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include <string>

#if !defined(PROD)
constexpr auto server_addr = "0.0.0.0";
constexpr auto server_port = 7676;
#endif

namespace common {

    constexpr auto SUCCESS =  0;
    constexpr auto FAILURE = (-1);

    constexpr auto TCP_SERVER = (1 << 0);
    constexpr auto TCP_CLIENT = (1 << 1);

    class HandleInfo {
       public:
        using handle = int;
        int m_type{};
        int m_fd{};
        std::string m_name;
    };

    using handle = typename HandleInfo::handle;
}  // namespace common
#endif
   // namespace common