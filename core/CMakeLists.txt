cmake_minimum_required(VERSION 3.15)

include_directories(${PROJECT_SOURCE_DIR}/common/inc)
include_directories(${PROJECT_SOURCE_DIR}/core/inc)
include_directories(${PROJECT_SOURCE_DIR}/adapter/inc/)
include_directories(${PROJECT_SOURCE_DIR}/app/inc/)


file(GLOB CORE_SRC src/*.cpp)

add_library(libCore STATIC ${CORE_SRC})

