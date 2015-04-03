cmake_minimum_required(VERSION 2.8.4)
project(OS_homeworks)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES lib/helpers.c lib/helpers.h cat/cat.c revwords/revwords.c filter/filter.c lib/bufio.c lib/bufio.h bufcat/bufcat.c)
add_executable(OS_homeworks ${SOURCE_FILES})

