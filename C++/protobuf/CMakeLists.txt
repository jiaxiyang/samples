cmake_minimum_required(VERSION 3.5)
project(proto_test)
add_definitions("-DNDEBUG" "-O3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11")

find_package(Protobuf REQUIRED)
message(STATUS ${PROTOBUF_INCLUDE_DIR})
message(STATUS ${PROTOBUF_LIBRARY})
include_directories(${PROTOBUF_INCLUDE_DIR})

set(COMMON "common")
add_library(${COMMON}
  test.pb.h
  test.pb.cc
  )


# target_link_libraries(proto_test protobuf::libprotobuf)
add_executable(generate_proto generate_proto.cc)
add_executable(show_proto show_proto.cc)
add_executable(compare_proto compare_proto.cc)
target_link_libraries(generate_proto ${COMMON} ${PROTOBUF_LIBRARY} -lpthread)
target_link_libraries(show_proto ${COMMON} ${PROTOBUF_LIBRARY} -lpthread)
target_link_libraries(compare_proto ${COMMON} ${PROTOBUF_LIBRARY} -lpthread)

# cmake --help-module FindProtobuf : protobuf cmake use
