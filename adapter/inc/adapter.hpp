#ifndef _POLLENGINE_ADAPTER_INC_ADAPTER_HPP
#define _POLLENGINE_ADAPTER_INC_ADAPTER_HPP

#pragma once
#include <functional>
#include <map>
#include <vector>

#include "common.hpp"

// forward declaration for the UserObj
namespace app {
    class UserObj;
}  // namespace app
/**
 * @brief This is adapter namespace
 */
namespace adapter {
    /**
     * @brief class Adapter
     * * This abstracts the core poll facility from the App
     * TODO: make m_handles and m_callbacks hide from App
     */
    class Adapter {
        using callback = std::function<int(int)>;
        // stores the App pointer on behalf of which this adapter is working
        app::UserObj* entity;
        // Add a handle to m_handles
        // also registers default callbacks
        void addHandle(common::HandleInfo&& handle);

       public:
        explicit Adapter(app::UserObj* entity);
        auto configure(int flags) -> int;
        // TODO(deka): make these hide from user
        // TODO(deka): but these are also needed by core
        std::vector<common::HandleInfo> m_handles;
        std::map<common::handle, callback> m_callbacks;
    };
}  // namespace adapter
#endif
   // namespace adapter