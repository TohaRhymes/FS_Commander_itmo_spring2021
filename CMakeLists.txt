cmake_minimum_required(VERSION 3.17)
project(SPO_file_system C)

set(CMAKE_C_STANDARD 11)

add_executable(SPO_file_system main.c)
target_link_libraries(SPO_file_system blkid)