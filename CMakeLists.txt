cmake_minimum_required(VERSION 3.31)
project(graph_generator)

set(CMAKE_CXX_STANDARD 20)

#find_package(PkgConfig REQUIRED)
#pkg_check_modules(BOOST REQUIRED boost)

set(BOOST_ROOT "/Users/klaudia/boost")
set(BOOST_INCLUDEDIR "/Users/klaudia/boost")
set(BOOST_LIBRARYDIR "/Users/klaudia/boost/stage/lib")

find_package(Boost REQUIRED COMPONENTS graph)

add_executable(graph_generator main.cpp myGraph.cpp
        bipartiteGraph.cpp
        completeGraph.cpp)

target_include_directories(graph_generator PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(graph_generator PRIVATE ${Boost_LIBRARIES})
#include_directories(${BOOST_INCLUDE_DIRS})

#target_link_libraries(graph_generator ${BOOST_LIBRARIES})


