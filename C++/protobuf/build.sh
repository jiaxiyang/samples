#!/bin/bash

protoc -I=. --cpp_out=. ./test.proto

mkdir -p build
cd build
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=on ..
make
