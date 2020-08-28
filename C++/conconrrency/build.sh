#!/bin/bash

mkdir -p build

cd build
g++ -o data_race ../src/data_race.cpp -std=c++17 -pthread
g++ -o dead_lock ../src/dead_lock.cpp -std=c++17 -pthread
g++ -o mutex ../src/mutex.cpp -std=c++17 -pthread
g++ -o future ../src/future.cpp -std=c++17 -pthread
g++ -o condition_variable ../src/condition_variable.cpp -std=c++17 -pthread
g++ -o parallel_algorithms ../src/parallel_algorithms.cpp -std=c++17 -pthread
