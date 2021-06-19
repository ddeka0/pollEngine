cmake_minimum_required(VERSION 3.15)

include_directories(${PROJECT_SOURCE_DIR}/common/inc)


file(GLOB COMMON_SRC src/*.cpp)

add_library(libCommon STATIC ${COMMON_SRC})

