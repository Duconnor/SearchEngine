cmake_minimum_required(VERSION 3.10)
project(SearchEngine)

set(CMAKE_CXX_STANDARD 11)

add_executable(SearchEngine main.cpp invertedlist.h invertedlist.cpp searchengine.h searchengine.cpp jieba.h)