#include <iostream>

#include "myapp.hpp"

auto main() -> int {
    test::App app;
    if (app.configureAs(common::TCP_SERVER) != 0) {
        std::cout << "App can not be started!" << std::endl;
        return 0;
    }
    std::cout << "App running ..." << std::endl;
    app.run();
}