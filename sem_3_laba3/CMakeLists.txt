cmake_minimum_required(VERSION 3.20)
project(sem_3_laba3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES sem_3_laba3 main.cpp Graph.h ListSequence.h Sequence.h LinkedList.h DynamicArray.h ArraySequence.h Board.h GUI.h MMA.h)
add_executable(${SOURCE_FILES} Tests.h Tests.h)
include_directories(/usr/local/include)
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(sem_3_laba3 sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
