cmake_minimum_required(VERSION 3.14)
project(sem_3_laba2)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES sem_3_laba2 main.cpp MMA.h Tree.h Board.h GUI.h BinaryTree.h Sequence.h DynamicArray.h ArraySequence.h ISet.h Set.h)
add_executable(${SOURCE_FILES} Tests.h)
include_directories(/usr/local/include)
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(sem_3_laba2 sfml-system sfml-window sfml-graphics sfml-audio sfml-network)




