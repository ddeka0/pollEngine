cmake_minimum_required(VERSION 3.15)

include_directories(${PROJECT_SOURCE_DIR}/app/inc/)


file(GLOB APP_SRC src/*.cpp)

add_library(libApp STATIC ${APP_SRC})

