cmake_minimum_required(VERSION 3.5)
project(proto_test)
aux_source_directory(. DIR_SRCS)
add_definitions("-DNDEBUG" "-O3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_executable(proto_test ${DIR_SRCS})

find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIR})
# target_link_libraries(proto_test protobuf::libprotobuf)
target_link_libraries(proto_test ${PROTOBUF_LIBRARY})
message(STATUS ${PROTOBUF_INCLUDE_DIR})
message(STATUS ${PROTOBUF_LIBRARY})

# cmake --help-module FindProtobuf : protobuf cmake use
