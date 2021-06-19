#ifndef _HOME_DEKA_ACADEMIC_POLLENGINE_APP_INC_APP_HPP
#define _HOME_DEKA_ACADEMIC_POLLENGINE_APP_INC_APP_HPP

#pragma once

namespace adapter {
    class Adapter;
}  // namespace adapter

namespace app {
    class UserObj {
       public:
        explicit UserObj();
        virtual ~UserObj();
        virtual void run();
        [[nodiscard]] virtual auto getAdapter() const
            -> const adapter::Adapter& = 0;
    };
}  // namespace app
#endif
   // namespace app