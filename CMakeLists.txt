cmake_minimum_required(VERSION 3.17)
project(SPO_file_system C CXX)

set(CMAKE_C_STANDARD 11)


add_executable(SPO_file_system main.h main.c genius_info.h genius_info.c genius_ntfs.h genius_ntfs.c genius_commander.h genius_commander.c)
target_link_libraries(SPO_file_system blkid)