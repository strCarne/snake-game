cmake_minimum_required(VERSION 3.25)
project(snake-game)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

file(GLOB SOURCE CONFIGURE_DEPENDS "src/*.cpp")

include_directories(include)

add_executable(${PROJECT_NAME} ${SOURCE})

include_directories(objects)
add_subdirectory(objects)
target_link_libraries(${PROJECT_NAME} objects)

find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio sfml-network)