cmake_minimum_required(VERSION 3.10)

project(GameEngineTemplate)

#set cpp standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(engine)
add_subdirectory(game)