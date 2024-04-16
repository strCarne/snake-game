cmake_minimum_required(VERSION 3.25)
project(snake-game)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
set(CMAKE_CXX_STANDARD 20)

add_executable(
        snake-game

        main.cpp

        DisplayObject.hpp
        DisplayObject.cpp

        GameMap.hpp
        GameMap.cpp

        Rectangle.hpp
        Rectangle.cpp

        Circle.hpp
        Circle.cpp

        EllipseShape.hpp

        Ellipse.hpp
        Ellipse.cpp

        Triangle.hpp
        Triangle.cpp

        Line.hpp
        Line.cpp

        Randomizer.hpp
        Randomizer.cpp

        Controller.hpp
        Controller.cpp

        Vector4.hpp

        Button.hpp
        Button.cpp
)

include_directories(/usr/local/include)

find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})

include_directories("~/SFML/include/")
target_link_libraries(snake-game sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
