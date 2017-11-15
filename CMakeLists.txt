cmake_minimum_required(VERSION 3.8)
project(MusicLibrary)

set(CMAKE_CXX_STANDARD 11)

#[[set source files to be compiled, set name of exectuable and pass in source files variable]]
set(SOURCE_FILES Main.cpp InputTools.cpp Song.cpp SongList.cpp UserInterface.cpp)
add_executable(MusicLibrary ${SOURCE_FILES})