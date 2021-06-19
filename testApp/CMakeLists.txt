cmake_minimum_required(VERSION 3.15)

include_directories(${PROJECT_SOURCE_DIR}/common/inc)
include_directories(${PROJECT_SOURCE_DIR}/adapter/inc/)
include_directories(${PROJECT_SOURCE_DIR}/app/inc/)
include_directories(${PROJECT_SOURCE_DIR}/testApp/inc/)


file(GLOB TEST_SRC src/*.cpp)


add_executable(${PROJECT_NAME}
    ${TEST_SRC}
)

target_link_libraries(${PROJECT_NAME}
libAdapter
libApp
libCommon
libCore
)