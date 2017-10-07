cmake_minimum_required(VERSION 3.9)
project(NeuralNet)

set(CMAKE_CXX_STANDARD 11)

# OpenNN
set(OPENNN_SOURCE_DIR /Users/dungphan/Documents/GitHub/OpenNN/OpenNN/)
set(OPENNN_BUILD_DIR /Users/dungphan/Documents/GitHub/OpenNN/OpenNN-build/)
include_directories(${OPENNN_SOURCE_DIR}/opennn/)
link_directories(${OPENNN_BUILD_DIR}/opennn/)
link_directories(${OPENNN_BUILD_DIR}/tinyxml2/)

set(SOURCE_FILES main.cpp)
add_executable(NeuralNet ${SOURCE_FILES})

target_link_libraries(NeuralNet opennn tinyxml2)
configure_file(banknotes.dat banknotes.dat COPYONLY)