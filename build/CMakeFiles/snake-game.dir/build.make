# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.27.6/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.27.6/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/strCarne/Desktop/snake-game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/strCarne/Desktop/snake-game/build

# Include any dependencies generated for this target.
include CMakeFiles/snake-game.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/snake-game.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/snake-game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/snake-game.dir/flags.make

CMakeFiles/snake-game.dir/main.cpp.o: CMakeFiles/snake-game.dir/flags.make
CMakeFiles/snake-game.dir/main.cpp.o: /Users/strCarne/Desktop/snake-game/main.cpp
CMakeFiles/snake-game.dir/main.cpp.o: CMakeFiles/snake-game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/strCarne/Desktop/snake-game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/snake-game.dir/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/snake-game.dir/main.cpp.o -MF CMakeFiles/snake-game.dir/main.cpp.o.d -o CMakeFiles/snake-game.dir/main.cpp.o -c /Users/strCarne/Desktop/snake-game/main.cpp

CMakeFiles/snake-game.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/snake-game.dir/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/strCarne/Desktop/snake-game/main.cpp > CMakeFiles/snake-game.dir/main.cpp.i

CMakeFiles/snake-game.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/snake-game.dir/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/strCarne/Desktop/snake-game/main.cpp -o CMakeFiles/snake-game.dir/main.cpp.s

CMakeFiles/snake-game.dir/DisplayObject.cpp.o: CMakeFiles/snake-game.dir/flags.make
CMakeFiles/snake-game.dir/DisplayObject.cpp.o: /Users/strCarne/Desktop/snake-game/DisplayObject.cpp
CMakeFiles/snake-game.dir/DisplayObject.cpp.o: CMakeFiles/snake-game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/strCarne/Desktop/snake-game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/snake-game.dir/DisplayObject.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/snake-game.dir/DisplayObject.cpp.o -MF CMakeFiles/snake-game.dir/DisplayObject.cpp.o.d -o CMakeFiles/snake-game.dir/DisplayObject.cpp.o -c /Users/strCarne/Desktop/snake-game/DisplayObject.cpp

CMakeFiles/snake-game.dir/DisplayObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/snake-game.dir/DisplayObject.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/strCarne/Desktop/snake-game/DisplayObject.cpp > CMakeFiles/snake-game.dir/DisplayObject.cpp.i

CMakeFiles/snake-game.dir/DisplayObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/snake-game.dir/DisplayObject.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/strCarne/Desktop/snake-game/DisplayObject.cpp -o CMakeFiles/snake-game.dir/DisplayObject.cpp.s

CMakeFiles/snake-game.dir/GameMap.cpp.o: CMakeFiles/snake-game.dir/flags.make
CMakeFiles/snake-game.dir/GameMap.cpp.o: /Users/strCarne/Desktop/snake-game/GameMap.cpp
CMakeFiles/snake-game.dir/GameMap.cpp.o: CMakeFiles/snake-game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/strCarne/Desktop/snake-game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/snake-game.dir/GameMap.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/snake-game.dir/GameMap.cpp.o -MF CMakeFiles/snake-game.dir/GameMap.cpp.o.d -o CMakeFiles/snake-game.dir/GameMap.cpp.o -c /Users/strCarne/Desktop/snake-game/GameMap.cpp

CMakeFiles/snake-game.dir/GameMap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/snake-game.dir/GameMap.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/strCarne/Desktop/snake-game/GameMap.cpp > CMakeFiles/snake-game.dir/GameMap.cpp.i

CMakeFiles/snake-game.dir/GameMap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/snake-game.dir/GameMap.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/strCarne/Desktop/snake-game/GameMap.cpp -o CMakeFiles/snake-game.dir/GameMap.cpp.s

CMakeFiles/snake-game.dir/Rectangle.cpp.o: CMakeFiles/snake-game.dir/flags.make
CMakeFiles/snake-game.dir/Rectangle.cpp.o: /Users/strCarne/Desktop/snake-game/Rectangle.cpp
CMakeFiles/snake-game.dir/Rectangle.cpp.o: CMakeFiles/snake-game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/strCarne/Desktop/snake-game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/snake-game.dir/Rectangle.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/snake-game.dir/Rectangle.cpp.o -MF CMakeFiles/snake-game.dir/Rectangle.cpp.o.d -o CMakeFiles/snake-game.dir/Rectangle.cpp.o -c /Users/strCarne/Desktop/snake-game/Rectangle.cpp

CMakeFiles/snake-game.dir/Rectangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/snake-game.dir/Rectangle.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/strCarne/Desktop/snake-game/Rectangle.cpp > CMakeFiles/snake-game.dir/Rectangle.cpp.i

CMakeFiles/snake-game.dir/Rectangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/snake-game.dir/Rectangle.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/strCarne/Desktop/snake-game/Rectangle.cpp -o CMakeFiles/snake-game.dir/Rectangle.cpp.s

CMakeFiles/snake-game.dir/Circle.cpp.o: CMakeFiles/snake-game.dir/flags.make
CMakeFiles/snake-game.dir/Circle.cpp.o: /Users/strCarne/Desktop/snake-game/Circle.cpp
CMakeFiles/snake-game.dir/Circle.cpp.o: CMakeFiles/snake-game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/strCarne/Desktop/snake-game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/snake-game.dir/Circle.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/snake-game.dir/Circle.cpp.o -MF CMakeFiles/snake-game.dir/Circle.cpp.o.d -o CMakeFiles/snake-game.dir/Circle.cpp.o -c /Users/strCarne/Desktop/snake-game/Circle.cpp

CMakeFiles/snake-game.dir/Circle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/snake-game.dir/Circle.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/strCarne/Desktop/snake-game/Circle.cpp > CMakeFiles/snake-game.dir/Circle.cpp.i

CMakeFiles/snake-game.dir/Circle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/snake-game.dir/Circle.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/strCarne/Desktop/snake-game/Circle.cpp -o CMakeFiles/snake-game.dir/Circle.cpp.s

CMakeFiles/snake-game.dir/Ellipse.cpp.o: CMakeFiles/snake-game.dir/flags.make
CMakeFiles/snake-game.dir/Ellipse.cpp.o: /Users/strCarne/Desktop/snake-game/Ellipse.cpp
CMakeFiles/snake-game.dir/Ellipse.cpp.o: CMakeFiles/snake-game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/strCarne/Desktop/snake-game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/snake-game.dir/Ellipse.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/snake-game.dir/Ellipse.cpp.o -MF CMakeFiles/snake-game.dir/Ellipse.cpp.o.d -o CMakeFiles/snake-game.dir/Ellipse.cpp.o -c /Users/strCarne/Desktop/snake-game/Ellipse.cpp

CMakeFiles/snake-game.dir/Ellipse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/snake-game.dir/Ellipse.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/strCarne/Desktop/snake-game/Ellipse.cpp > CMakeFiles/snake-game.dir/Ellipse.cpp.i

CMakeFiles/snake-game.dir/Ellipse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/snake-game.dir/Ellipse.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/strCarne/Desktop/snake-game/Ellipse.cpp -o CMakeFiles/snake-game.dir/Ellipse.cpp.s

CMakeFiles/snake-game.dir/Triangle.cpp.o: CMakeFiles/snake-game.dir/flags.make
CMakeFiles/snake-game.dir/Triangle.cpp.o: /Users/strCarne/Desktop/snake-game/Triangle.cpp
CMakeFiles/snake-game.dir/Triangle.cpp.o: CMakeFiles/snake-game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/strCarne/Desktop/snake-game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/snake-game.dir/Triangle.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/snake-game.dir/Triangle.cpp.o -MF CMakeFiles/snake-game.dir/Triangle.cpp.o.d -o CMakeFiles/snake-game.dir/Triangle.cpp.o -c /Users/strCarne/Desktop/snake-game/Triangle.cpp

CMakeFiles/snake-game.dir/Triangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/snake-game.dir/Triangle.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/strCarne/Desktop/snake-game/Triangle.cpp > CMakeFiles/snake-game.dir/Triangle.cpp.i

CMakeFiles/snake-game.dir/Triangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/snake-game.dir/Triangle.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/strCarne/Desktop/snake-game/Triangle.cpp -o CMakeFiles/snake-game.dir/Triangle.cpp.s

CMakeFiles/snake-game.dir/Line.cpp.o: CMakeFiles/snake-game.dir/flags.make
CMakeFiles/snake-game.dir/Line.cpp.o: /Users/strCarne/Desktop/snake-game/Line.cpp
CMakeFiles/snake-game.dir/Line.cpp.o: CMakeFiles/snake-game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/strCarne/Desktop/snake-game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/snake-game.dir/Line.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/snake-game.dir/Line.cpp.o -MF CMakeFiles/snake-game.dir/Line.cpp.o.d -o CMakeFiles/snake-game.dir/Line.cpp.o -c /Users/strCarne/Desktop/snake-game/Line.cpp

CMakeFiles/snake-game.dir/Line.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/snake-game.dir/Line.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/strCarne/Desktop/snake-game/Line.cpp > CMakeFiles/snake-game.dir/Line.cpp.i

CMakeFiles/snake-game.dir/Line.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/snake-game.dir/Line.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/strCarne/Desktop/snake-game/Line.cpp -o CMakeFiles/snake-game.dir/Line.cpp.s

CMakeFiles/snake-game.dir/Randomizer.cpp.o: CMakeFiles/snake-game.dir/flags.make
CMakeFiles/snake-game.dir/Randomizer.cpp.o: /Users/strCarne/Desktop/snake-game/Randomizer.cpp
CMakeFiles/snake-game.dir/Randomizer.cpp.o: CMakeFiles/snake-game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/strCarne/Desktop/snake-game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/snake-game.dir/Randomizer.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/snake-game.dir/Randomizer.cpp.o -MF CMakeFiles/snake-game.dir/Randomizer.cpp.o.d -o CMakeFiles/snake-game.dir/Randomizer.cpp.o -c /Users/strCarne/Desktop/snake-game/Randomizer.cpp

CMakeFiles/snake-game.dir/Randomizer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/snake-game.dir/Randomizer.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/strCarne/Desktop/snake-game/Randomizer.cpp > CMakeFiles/snake-game.dir/Randomizer.cpp.i

CMakeFiles/snake-game.dir/Randomizer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/snake-game.dir/Randomizer.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/strCarne/Desktop/snake-game/Randomizer.cpp -o CMakeFiles/snake-game.dir/Randomizer.cpp.s

CMakeFiles/snake-game.dir/Controller.cpp.o: CMakeFiles/snake-game.dir/flags.make
CMakeFiles/snake-game.dir/Controller.cpp.o: /Users/strCarne/Desktop/snake-game/Controller.cpp
CMakeFiles/snake-game.dir/Controller.cpp.o: CMakeFiles/snake-game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/strCarne/Desktop/snake-game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/snake-game.dir/Controller.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/snake-game.dir/Controller.cpp.o -MF CMakeFiles/snake-game.dir/Controller.cpp.o.d -o CMakeFiles/snake-game.dir/Controller.cpp.o -c /Users/strCarne/Desktop/snake-game/Controller.cpp

CMakeFiles/snake-game.dir/Controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/snake-game.dir/Controller.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/strCarne/Desktop/snake-game/Controller.cpp > CMakeFiles/snake-game.dir/Controller.cpp.i

CMakeFiles/snake-game.dir/Controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/snake-game.dir/Controller.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/strCarne/Desktop/snake-game/Controller.cpp -o CMakeFiles/snake-game.dir/Controller.cpp.s

# Object files for target snake-game
snake__game_OBJECTS = \
"CMakeFiles/snake-game.dir/main.cpp.o" \
"CMakeFiles/snake-game.dir/DisplayObject.cpp.o" \
"CMakeFiles/snake-game.dir/GameMap.cpp.o" \
"CMakeFiles/snake-game.dir/Rectangle.cpp.o" \
"CMakeFiles/snake-game.dir/Circle.cpp.o" \
"CMakeFiles/snake-game.dir/Ellipse.cpp.o" \
"CMakeFiles/snake-game.dir/Triangle.cpp.o" \
"CMakeFiles/snake-game.dir/Line.cpp.o" \
"CMakeFiles/snake-game.dir/Randomizer.cpp.o" \
"CMakeFiles/snake-game.dir/Controller.cpp.o"

# External object files for target snake-game
snake__game_EXTERNAL_OBJECTS =

snake-game: CMakeFiles/snake-game.dir/main.cpp.o
snake-game: CMakeFiles/snake-game.dir/DisplayObject.cpp.o
snake-game: CMakeFiles/snake-game.dir/GameMap.cpp.o
snake-game: CMakeFiles/snake-game.dir/Rectangle.cpp.o
snake-game: CMakeFiles/snake-game.dir/Circle.cpp.o
snake-game: CMakeFiles/snake-game.dir/Ellipse.cpp.o
snake-game: CMakeFiles/snake-game.dir/Triangle.cpp.o
snake-game: CMakeFiles/snake-game.dir/Line.cpp.o
snake-game: CMakeFiles/snake-game.dir/Randomizer.cpp.o
snake-game: CMakeFiles/snake-game.dir/Controller.cpp.o
snake-game: CMakeFiles/snake-game.dir/build.make
snake-game: /usr/local/lib/libsfml-graphics.2.6.1.dylib
snake-game: /usr/local/lib/libsfml-audio.2.6.1.dylib
snake-game: /usr/local/lib/libsfml-network.2.6.1.dylib
snake-game: /usr/local/lib/libsfml-window.2.6.1.dylib
snake-game: /usr/local/lib/libsfml-system.2.6.1.dylib
snake-game: CMakeFiles/snake-game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/strCarne/Desktop/snake-game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable snake-game"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/snake-game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/snake-game.dir/build: snake-game
.PHONY : CMakeFiles/snake-game.dir/build

CMakeFiles/snake-game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/snake-game.dir/cmake_clean.cmake
.PHONY : CMakeFiles/snake-game.dir/clean

CMakeFiles/snake-game.dir/depend:
	cd /Users/strCarne/Desktop/snake-game/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/strCarne/Desktop/snake-game /Users/strCarne/Desktop/snake-game /Users/strCarne/Desktop/snake-game/build /Users/strCarne/Desktop/snake-game/build /Users/strCarne/Desktop/snake-game/build/CMakeFiles/snake-game.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/snake-game.dir/depend
