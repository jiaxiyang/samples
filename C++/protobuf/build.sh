#!/bin/bash

protoc -I=. --cpp_out=. ./test.proto

mkdir -p build
cd build
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=on ..
make

./generate_proto
./show_proto output.bin
cp output.bin output1.bin
./compare_proto output.bin output1.bin
