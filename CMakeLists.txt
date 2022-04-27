cmake_minimum_required(VERSION 3.0.0)
project(OO-tui VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 11)

#add all files in the src directory to executable
#file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
set(SRC_FILES src/main.cpp src/OO-tui/OOtui.cpp src/OO-tui/Clear.cpp src/OO-tui/Circle.cpp src/OO-tui/Element.cpp)
#add -fsanitize=address to the compiler debug flags
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address")

add_executable(OO-tui ${SRC_FILES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
