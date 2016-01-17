cmake_minimum_required(VERSION 2.8)
project(UDP_Synchronizer_Client)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp UDPClient.cpp UDPClient.h utils.cpp utils.h)

find_package(Boost COMPONENTS system filesystem thread REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

find_package (Threads)

add_executable(UDP_Synchronizer_Client ${SOURCE_FILES})

target_link_libraries( UDP_Synchronizer_Client ${Boost_LIBRARIES} )
target_link_libraries (UDP_Synchronizer_Client ${CMAKE_THREAD_LIBS_INIT})
