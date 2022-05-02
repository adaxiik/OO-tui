cmake_minimum_required(VERSION 3.0.0)
project(OO-tui VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 11)

#add all files in the src directory to executable
file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/OO-tui/*.cpp)

#set(SRC_FILES src/main.cpp src/OO-tui/OOtui.cpp src/OO-tui/Clear.cpp src/OO-tui/Circle.cpp src/OO-tui/Element.cpp)
#add -fsanitize=address to the compiler debug flags
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2 -flto -march=native")

add_executable(OO-tui src/main.cpp ${SRC_FILES})
target_link_libraries(OO-tui ncurses)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
