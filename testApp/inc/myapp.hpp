#ifndef _POLLENGINE_TESTAPP_INC_MYAPP_HPP
#define _POLLENGINE_TESTAPP_INC_MYAPP_HPP

#pragma once
#include <functional>
#include <map>

#include "adapter.hpp"
#include "app.hpp"

using namespace common;

namespace test {
    class App : public app::UserObj {
       public:
        App();
        ~App() override;
        auto configureAs(int flags) -> int;
        void registerCallBack(int type, std::function<int(int)> callback);
        [[nodiscard]] auto getAdapter() const
            -> const adapter::Adapter& override;

       private:
        adapter::Adapter m_adapter;
    };
}  // namespace test

#endif
