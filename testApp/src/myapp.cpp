#include "myapp.hpp"

#include <iostream>

namespace test {

    App::App() : m_adapter(this) { std::cout << "App Created!" << std::endl; }

    App::~App() { std::cout << "App Destroyed!" << std::endl; }

    int App::configureAs(int flags) { return m_adapter.configure(flags); }

    const adapter::Adapter& App::getAdapter() const { return m_adapter; }

    void App::registerCallBack(int type, std::function<int(int)> callback) {}

}  // namespace test