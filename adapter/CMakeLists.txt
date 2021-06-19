cmake_minimum_required(VERSION 3.15)

include_directories(${PROJECT_SOURCE_DIR}/common/inc)
include_directories(${PROJECT_SOURCE_DIR}/adapter/inc/)
include_directories(${PROJECT_SOURCE_DIR}/app/inc/)

file(GLOB ADAPTER_SRC src/*.cpp)

add_library(libAdapter STATIC ${ADAPTER_SRC})

