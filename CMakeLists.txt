cmake_minimum_required(VERSION 3.17)
project(NetSim)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -Wextra -Werror -Wpedantic -pedantic-errors -Werror=switch)

include_directories(
        include
        netsim_tests/mocks
        netsim_tests/include
)

set(SOURCE_FILES
        src/package.cpp
        src/storage_types.cpp
        src/nodes.cpp
        src/helpers.cpp
        src/factory.cpp
        )

add_executable(NetSim ${SOURCE_FILES} main.cpp)

set(SOURCE_FILES_TESTS
        netsim_tests/test/test_package.cpp
        netsim_tests/test/test_storage_types.cpp
        netsim_tests/test/test_nodes.cpp
        netsim_tests/test/test_Factory.cpp
        )

add_executable(NetSim__test ${SOURCE_FILES} ${SOURCE_FILES_TESTS} netsim_tests/test/main_gtest.cpp)

target_include_directories(NetSim__test PUBLIC
        ../../googletest-master/googlemock/include
        ../../googletest-master/googletest/include
        mocks
        )

add_subdirectory(googletest-master)

target_link_libraries(NetSim__test gmock)