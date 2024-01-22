cmake_minimum_required(VERSION 3.0.0)
project(text_editor VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

find_package(GTest REQUIRED)

add_executable(text_editor main.cpp
                            fileHandler.cpp
                            boyerMoore.cpp)

target_link_libraries(text_editor GTest::GTest GTest::Main)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
