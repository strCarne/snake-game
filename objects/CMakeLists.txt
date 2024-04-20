cmake_minimum_required(VERSION 3.25)

project(objects
        VERSION 1.0
        LANGUAGES CXX
        DESCRIPTION graphical-primitives-library
        HOMEPAGE_URL https://github.com/strCarne/objects
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories(include)

file(GLOB LIB_SOURCE CONFIGURE_DEPENDS "src/*.cpp")

add_library(${PROJECT_NAME} SHARED ${LIB_SOURCE})

find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
