cmake_minimum_required(VERSION 3.10)
project(TP14_2 C)

set(CMAKE_C_STANDARD 99)

add_executable(TP14_2 main.c recherche.h recherche.c cmake-build-debug/dict_anglais.txt cmake-build-debug/dict_anglais2.txt)