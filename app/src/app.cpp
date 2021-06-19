#include "app.hpp"

namespace core {
    extern auto eventLoop(const app::UserObj* entity) -> int;
} // namespace core

namespace app {
    UserObj::UserObj() = default;
    UserObj::~UserObj() = default;
    void UserObj::run() { core::eventLoop(this); }
}  // namespace app