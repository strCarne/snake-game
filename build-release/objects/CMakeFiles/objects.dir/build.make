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
CMAKE_SOURCE_DIR = /Users/strCarne/Documents/Projects/C++/snake-game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/strCarne/Documents/Projects/C++/snake-game/build-release

# Include any dependencies generated for this target.
include objects/CMakeFiles/objects.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include objects/CMakeFiles/objects.dir/compiler_depend.make

# Include the progress variables for this target.
include objects/CMakeFiles/objects.dir/progress.make

# Include the compile flags for this target's objects.
include objects/CMakeFiles/objects.dir/flags.make

objects/CMakeFiles/objects.dir/src/circle.cc.o: objects/CMakeFiles/objects.dir/flags.make
objects/CMakeFiles/objects.dir/src/circle.cc.o: /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/circle.cc
objects/CMakeFiles/objects.dir/src/circle.cc.o: objects/CMakeFiles/objects.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/strCarne/Documents/Projects/C++/snake-game/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object objects/CMakeFiles/objects.dir/src/circle.cc.o"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT objects/CMakeFiles/objects.dir/src/circle.cc.o -MF CMakeFiles/objects.dir/src/circle.cc.o.d -o CMakeFiles/objects.dir/src/circle.cc.o -c /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/circle.cc

objects/CMakeFiles/objects.dir/src/circle.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/objects.dir/src/circle.cc.i"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/circle.cc > CMakeFiles/objects.dir/src/circle.cc.i

objects/CMakeFiles/objects.dir/src/circle.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/objects.dir/src/circle.cc.s"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/circle.cc -o CMakeFiles/objects.dir/src/circle.cc.s

objects/CMakeFiles/objects.dir/src/color_picker.cc.o: objects/CMakeFiles/objects.dir/flags.make
objects/CMakeFiles/objects.dir/src/color_picker.cc.o: /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/color_picker.cc
objects/CMakeFiles/objects.dir/src/color_picker.cc.o: objects/CMakeFiles/objects.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/strCarne/Documents/Projects/C++/snake-game/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object objects/CMakeFiles/objects.dir/src/color_picker.cc.o"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT objects/CMakeFiles/objects.dir/src/color_picker.cc.o -MF CMakeFiles/objects.dir/src/color_picker.cc.o.d -o CMakeFiles/objects.dir/src/color_picker.cc.o -c /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/color_picker.cc

objects/CMakeFiles/objects.dir/src/color_picker.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/objects.dir/src/color_picker.cc.i"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/color_picker.cc > CMakeFiles/objects.dir/src/color_picker.cc.i

objects/CMakeFiles/objects.dir/src/color_picker.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/objects.dir/src/color_picker.cc.s"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/color_picker.cc -o CMakeFiles/objects.dir/src/color_picker.cc.s

objects/CMakeFiles/objects.dir/src/controller.cc.o: objects/CMakeFiles/objects.dir/flags.make
objects/CMakeFiles/objects.dir/src/controller.cc.o: /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/controller.cc
objects/CMakeFiles/objects.dir/src/controller.cc.o: objects/CMakeFiles/objects.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/strCarne/Documents/Projects/C++/snake-game/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object objects/CMakeFiles/objects.dir/src/controller.cc.o"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT objects/CMakeFiles/objects.dir/src/controller.cc.o -MF CMakeFiles/objects.dir/src/controller.cc.o.d -o CMakeFiles/objects.dir/src/controller.cc.o -c /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/controller.cc

objects/CMakeFiles/objects.dir/src/controller.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/objects.dir/src/controller.cc.i"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/controller.cc > CMakeFiles/objects.dir/src/controller.cc.i

objects/CMakeFiles/objects.dir/src/controller.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/objects.dir/src/controller.cc.s"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/controller.cc -o CMakeFiles/objects.dir/src/controller.cc.s

objects/CMakeFiles/objects.dir/src/display_object.cc.o: objects/CMakeFiles/objects.dir/flags.make
objects/CMakeFiles/objects.dir/src/display_object.cc.o: /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/display_object.cc
objects/CMakeFiles/objects.dir/src/display_object.cc.o: objects/CMakeFiles/objects.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/strCarne/Documents/Projects/C++/snake-game/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object objects/CMakeFiles/objects.dir/src/display_object.cc.o"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT objects/CMakeFiles/objects.dir/src/display_object.cc.o -MF CMakeFiles/objects.dir/src/display_object.cc.o.d -o CMakeFiles/objects.dir/src/display_object.cc.o -c /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/display_object.cc

objects/CMakeFiles/objects.dir/src/display_object.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/objects.dir/src/display_object.cc.i"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/display_object.cc > CMakeFiles/objects.dir/src/display_object.cc.i

objects/CMakeFiles/objects.dir/src/display_object.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/objects.dir/src/display_object.cc.s"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/display_object.cc -o CMakeFiles/objects.dir/src/display_object.cc.s

objects/CMakeFiles/objects.dir/src/ellipse.cc.o: objects/CMakeFiles/objects.dir/flags.make
objects/CMakeFiles/objects.dir/src/ellipse.cc.o: /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/ellipse.cc
objects/CMakeFiles/objects.dir/src/ellipse.cc.o: objects/CMakeFiles/objects.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/strCarne/Documents/Projects/C++/snake-game/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object objects/CMakeFiles/objects.dir/src/ellipse.cc.o"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT objects/CMakeFiles/objects.dir/src/ellipse.cc.o -MF CMakeFiles/objects.dir/src/ellipse.cc.o.d -o CMakeFiles/objects.dir/src/ellipse.cc.o -c /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/ellipse.cc

objects/CMakeFiles/objects.dir/src/ellipse.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/objects.dir/src/ellipse.cc.i"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/ellipse.cc > CMakeFiles/objects.dir/src/ellipse.cc.i

objects/CMakeFiles/objects.dir/src/ellipse.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/objects.dir/src/ellipse.cc.s"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/ellipse.cc -o CMakeFiles/objects.dir/src/ellipse.cc.s

objects/CMakeFiles/objects.dir/src/line.cc.o: objects/CMakeFiles/objects.dir/flags.make
objects/CMakeFiles/objects.dir/src/line.cc.o: /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/line.cc
objects/CMakeFiles/objects.dir/src/line.cc.o: objects/CMakeFiles/objects.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/strCarne/Documents/Projects/C++/snake-game/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object objects/CMakeFiles/objects.dir/src/line.cc.o"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT objects/CMakeFiles/objects.dir/src/line.cc.o -MF CMakeFiles/objects.dir/src/line.cc.o.d -o CMakeFiles/objects.dir/src/line.cc.o -c /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/line.cc

objects/CMakeFiles/objects.dir/src/line.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/objects.dir/src/line.cc.i"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/line.cc > CMakeFiles/objects.dir/src/line.cc.i

objects/CMakeFiles/objects.dir/src/line.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/objects.dir/src/line.cc.s"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/line.cc -o CMakeFiles/objects.dir/src/line.cc.s

objects/CMakeFiles/objects.dir/src/menu.cc.o: objects/CMakeFiles/objects.dir/flags.make
objects/CMakeFiles/objects.dir/src/menu.cc.o: /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/menu.cc
objects/CMakeFiles/objects.dir/src/menu.cc.o: objects/CMakeFiles/objects.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/strCarne/Documents/Projects/C++/snake-game/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object objects/CMakeFiles/objects.dir/src/menu.cc.o"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT objects/CMakeFiles/objects.dir/src/menu.cc.o -MF CMakeFiles/objects.dir/src/menu.cc.o.d -o CMakeFiles/objects.dir/src/menu.cc.o -c /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/menu.cc

objects/CMakeFiles/objects.dir/src/menu.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/objects.dir/src/menu.cc.i"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/menu.cc > CMakeFiles/objects.dir/src/menu.cc.i

objects/CMakeFiles/objects.dir/src/menu.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/objects.dir/src/menu.cc.s"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/menu.cc -o CMakeFiles/objects.dir/src/menu.cc.s

objects/CMakeFiles/objects.dir/src/menu2.cc.o: objects/CMakeFiles/objects.dir/flags.make
objects/CMakeFiles/objects.dir/src/menu2.cc.o: /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/menu2.cc
objects/CMakeFiles/objects.dir/src/menu2.cc.o: objects/CMakeFiles/objects.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/strCarne/Documents/Projects/C++/snake-game/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object objects/CMakeFiles/objects.dir/src/menu2.cc.o"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT objects/CMakeFiles/objects.dir/src/menu2.cc.o -MF CMakeFiles/objects.dir/src/menu2.cc.o.d -o CMakeFiles/objects.dir/src/menu2.cc.o -c /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/menu2.cc

objects/CMakeFiles/objects.dir/src/menu2.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/objects.dir/src/menu2.cc.i"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/menu2.cc > CMakeFiles/objects.dir/src/menu2.cc.i

objects/CMakeFiles/objects.dir/src/menu2.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/objects.dir/src/menu2.cc.s"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/menu2.cc -o CMakeFiles/objects.dir/src/menu2.cc.s

objects/CMakeFiles/objects.dir/src/menu_item.cc.o: objects/CMakeFiles/objects.dir/flags.make
objects/CMakeFiles/objects.dir/src/menu_item.cc.o: /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/menu_item.cc
objects/CMakeFiles/objects.dir/src/menu_item.cc.o: objects/CMakeFiles/objects.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/strCarne/Documents/Projects/C++/snake-game/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object objects/CMakeFiles/objects.dir/src/menu_item.cc.o"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT objects/CMakeFiles/objects.dir/src/menu_item.cc.o -MF CMakeFiles/objects.dir/src/menu_item.cc.o.d -o CMakeFiles/objects.dir/src/menu_item.cc.o -c /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/menu_item.cc

objects/CMakeFiles/objects.dir/src/menu_item.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/objects.dir/src/menu_item.cc.i"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/menu_item.cc > CMakeFiles/objects.dir/src/menu_item.cc.i

objects/CMakeFiles/objects.dir/src/menu_item.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/objects.dir/src/menu_item.cc.s"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/menu_item.cc -o CMakeFiles/objects.dir/src/menu_item.cc.s

objects/CMakeFiles/objects.dir/src/menu_item2.cc.o: objects/CMakeFiles/objects.dir/flags.make
objects/CMakeFiles/objects.dir/src/menu_item2.cc.o: /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/menu_item2.cc
objects/CMakeFiles/objects.dir/src/menu_item2.cc.o: objects/CMakeFiles/objects.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/strCarne/Documents/Projects/C++/snake-game/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object objects/CMakeFiles/objects.dir/src/menu_item2.cc.o"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT objects/CMakeFiles/objects.dir/src/menu_item2.cc.o -MF CMakeFiles/objects.dir/src/menu_item2.cc.o.d -o CMakeFiles/objects.dir/src/menu_item2.cc.o -c /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/menu_item2.cc

objects/CMakeFiles/objects.dir/src/menu_item2.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/objects.dir/src/menu_item2.cc.i"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/menu_item2.cc > CMakeFiles/objects.dir/src/menu_item2.cc.i

objects/CMakeFiles/objects.dir/src/menu_item2.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/objects.dir/src/menu_item2.cc.s"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/menu_item2.cc -o CMakeFiles/objects.dir/src/menu_item2.cc.s

objects/CMakeFiles/objects.dir/src/object_factory.cc.o: objects/CMakeFiles/objects.dir/flags.make
objects/CMakeFiles/objects.dir/src/object_factory.cc.o: /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/object_factory.cc
objects/CMakeFiles/objects.dir/src/object_factory.cc.o: objects/CMakeFiles/objects.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/strCarne/Documents/Projects/C++/snake-game/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object objects/CMakeFiles/objects.dir/src/object_factory.cc.o"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT objects/CMakeFiles/objects.dir/src/object_factory.cc.o -MF CMakeFiles/objects.dir/src/object_factory.cc.o.d -o CMakeFiles/objects.dir/src/object_factory.cc.o -c /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/object_factory.cc

objects/CMakeFiles/objects.dir/src/object_factory.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/objects.dir/src/object_factory.cc.i"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/object_factory.cc > CMakeFiles/objects.dir/src/object_factory.cc.i

objects/CMakeFiles/objects.dir/src/object_factory.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/objects.dir/src/object_factory.cc.s"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/object_factory.cc -o CMakeFiles/objects.dir/src/object_factory.cc.s

objects/CMakeFiles/objects.dir/src/object_params.cc.o: objects/CMakeFiles/objects.dir/flags.make
objects/CMakeFiles/objects.dir/src/object_params.cc.o: /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/object_params.cc
objects/CMakeFiles/objects.dir/src/object_params.cc.o: objects/CMakeFiles/objects.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/strCarne/Documents/Projects/C++/snake-game/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object objects/CMakeFiles/objects.dir/src/object_params.cc.o"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT objects/CMakeFiles/objects.dir/src/object_params.cc.o -MF CMakeFiles/objects.dir/src/object_params.cc.o.d -o CMakeFiles/objects.dir/src/object_params.cc.o -c /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/object_params.cc

objects/CMakeFiles/objects.dir/src/object_params.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/objects.dir/src/object_params.cc.i"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/object_params.cc > CMakeFiles/objects.dir/src/object_params.cc.i

objects/CMakeFiles/objects.dir/src/object_params.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/objects.dir/src/object_params.cc.s"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/object_params.cc -o CMakeFiles/objects.dir/src/object_params.cc.s

objects/CMakeFiles/objects.dir/src/randomizer.cc.o: objects/CMakeFiles/objects.dir/flags.make
objects/CMakeFiles/objects.dir/src/randomizer.cc.o: /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/randomizer.cc
objects/CMakeFiles/objects.dir/src/randomizer.cc.o: objects/CMakeFiles/objects.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/strCarne/Documents/Projects/C++/snake-game/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object objects/CMakeFiles/objects.dir/src/randomizer.cc.o"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT objects/CMakeFiles/objects.dir/src/randomizer.cc.o -MF CMakeFiles/objects.dir/src/randomizer.cc.o.d -o CMakeFiles/objects.dir/src/randomizer.cc.o -c /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/randomizer.cc

objects/CMakeFiles/objects.dir/src/randomizer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/objects.dir/src/randomizer.cc.i"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/randomizer.cc > CMakeFiles/objects.dir/src/randomizer.cc.i

objects/CMakeFiles/objects.dir/src/randomizer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/objects.dir/src/randomizer.cc.s"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/randomizer.cc -o CMakeFiles/objects.dir/src/randomizer.cc.s

objects/CMakeFiles/objects.dir/src/rectangle.cc.o: objects/CMakeFiles/objects.dir/flags.make
objects/CMakeFiles/objects.dir/src/rectangle.cc.o: /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/rectangle.cc
objects/CMakeFiles/objects.dir/src/rectangle.cc.o: objects/CMakeFiles/objects.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/strCarne/Documents/Projects/C++/snake-game/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object objects/CMakeFiles/objects.dir/src/rectangle.cc.o"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT objects/CMakeFiles/objects.dir/src/rectangle.cc.o -MF CMakeFiles/objects.dir/src/rectangle.cc.o.d -o CMakeFiles/objects.dir/src/rectangle.cc.o -c /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/rectangle.cc

objects/CMakeFiles/objects.dir/src/rectangle.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/objects.dir/src/rectangle.cc.i"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/rectangle.cc > CMakeFiles/objects.dir/src/rectangle.cc.i

objects/CMakeFiles/objects.dir/src/rectangle.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/objects.dir/src/rectangle.cc.s"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/rectangle.cc -o CMakeFiles/objects.dir/src/rectangle.cc.s

objects/CMakeFiles/objects.dir/src/text.cc.o: objects/CMakeFiles/objects.dir/flags.make
objects/CMakeFiles/objects.dir/src/text.cc.o: /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/text.cc
objects/CMakeFiles/objects.dir/src/text.cc.o: objects/CMakeFiles/objects.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/strCarne/Documents/Projects/C++/snake-game/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object objects/CMakeFiles/objects.dir/src/text.cc.o"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT objects/CMakeFiles/objects.dir/src/text.cc.o -MF CMakeFiles/objects.dir/src/text.cc.o.d -o CMakeFiles/objects.dir/src/text.cc.o -c /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/text.cc

objects/CMakeFiles/objects.dir/src/text.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/objects.dir/src/text.cc.i"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/text.cc > CMakeFiles/objects.dir/src/text.cc.i

objects/CMakeFiles/objects.dir/src/text.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/objects.dir/src/text.cc.s"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/text.cc -o CMakeFiles/objects.dir/src/text.cc.s

objects/CMakeFiles/objects.dir/src/triangle.cc.o: objects/CMakeFiles/objects.dir/flags.make
objects/CMakeFiles/objects.dir/src/triangle.cc.o: /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/triangle.cc
objects/CMakeFiles/objects.dir/src/triangle.cc.o: objects/CMakeFiles/objects.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/strCarne/Documents/Projects/C++/snake-game/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object objects/CMakeFiles/objects.dir/src/triangle.cc.o"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT objects/CMakeFiles/objects.dir/src/triangle.cc.o -MF CMakeFiles/objects.dir/src/triangle.cc.o.d -o CMakeFiles/objects.dir/src/triangle.cc.o -c /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/triangle.cc

objects/CMakeFiles/objects.dir/src/triangle.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/objects.dir/src/triangle.cc.i"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/triangle.cc > CMakeFiles/objects.dir/src/triangle.cc.i

objects/CMakeFiles/objects.dir/src/triangle.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/objects.dir/src/triangle.cc.s"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/strCarne/Documents/Projects/C++/snake-game/objects/src/triangle.cc -o CMakeFiles/objects.dir/src/triangle.cc.s

# Object files for target objects
objects_OBJECTS = \
"CMakeFiles/objects.dir/src/circle.cc.o" \
"CMakeFiles/objects.dir/src/color_picker.cc.o" \
"CMakeFiles/objects.dir/src/controller.cc.o" \
"CMakeFiles/objects.dir/src/display_object.cc.o" \
"CMakeFiles/objects.dir/src/ellipse.cc.o" \
"CMakeFiles/objects.dir/src/line.cc.o" \
"CMakeFiles/objects.dir/src/menu.cc.o" \
"CMakeFiles/objects.dir/src/menu2.cc.o" \
"CMakeFiles/objects.dir/src/menu_item.cc.o" \
"CMakeFiles/objects.dir/src/menu_item2.cc.o" \
"CMakeFiles/objects.dir/src/object_factory.cc.o" \
"CMakeFiles/objects.dir/src/object_params.cc.o" \
"CMakeFiles/objects.dir/src/randomizer.cc.o" \
"CMakeFiles/objects.dir/src/rectangle.cc.o" \
"CMakeFiles/objects.dir/src/text.cc.o" \
"CMakeFiles/objects.dir/src/triangle.cc.o"

# External object files for target objects
objects_EXTERNAL_OBJECTS =

objects/libobjects.dylib: objects/CMakeFiles/objects.dir/src/circle.cc.o
objects/libobjects.dylib: objects/CMakeFiles/objects.dir/src/color_picker.cc.o
objects/libobjects.dylib: objects/CMakeFiles/objects.dir/src/controller.cc.o
objects/libobjects.dylib: objects/CMakeFiles/objects.dir/src/display_object.cc.o
objects/libobjects.dylib: objects/CMakeFiles/objects.dir/src/ellipse.cc.o
objects/libobjects.dylib: objects/CMakeFiles/objects.dir/src/line.cc.o
objects/libobjects.dylib: objects/CMakeFiles/objects.dir/src/menu.cc.o
objects/libobjects.dylib: objects/CMakeFiles/objects.dir/src/menu2.cc.o
objects/libobjects.dylib: objects/CMakeFiles/objects.dir/src/menu_item.cc.o
objects/libobjects.dylib: objects/CMakeFiles/objects.dir/src/menu_item2.cc.o
objects/libobjects.dylib: objects/CMakeFiles/objects.dir/src/object_factory.cc.o
objects/libobjects.dylib: objects/CMakeFiles/objects.dir/src/object_params.cc.o
objects/libobjects.dylib: objects/CMakeFiles/objects.dir/src/randomizer.cc.o
objects/libobjects.dylib: objects/CMakeFiles/objects.dir/src/rectangle.cc.o
objects/libobjects.dylib: objects/CMakeFiles/objects.dir/src/text.cc.o
objects/libobjects.dylib: objects/CMakeFiles/objects.dir/src/triangle.cc.o
objects/libobjects.dylib: objects/CMakeFiles/objects.dir/build.make
objects/libobjects.dylib: /usr/local/lib/libsfml-graphics.2.6.1.dylib
objects/libobjects.dylib: /usr/local/lib/libsfml-audio.2.6.1.dylib
objects/libobjects.dylib: /usr/local/lib/libsfml-network.2.6.1.dylib
objects/libobjects.dylib: /usr/local/lib/libsfml-window.2.6.1.dylib
objects/libobjects.dylib: /usr/local/lib/libsfml-system.2.6.1.dylib
objects/libobjects.dylib: objects/CMakeFiles/objects.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/strCarne/Documents/Projects/C++/snake-game/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Linking CXX shared library libobjects.dylib"
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/objects.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
objects/CMakeFiles/objects.dir/build: objects/libobjects.dylib
.PHONY : objects/CMakeFiles/objects.dir/build

objects/CMakeFiles/objects.dir/clean:
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects && $(CMAKE_COMMAND) -P CMakeFiles/objects.dir/cmake_clean.cmake
.PHONY : objects/CMakeFiles/objects.dir/clean

objects/CMakeFiles/objects.dir/depend:
	cd /Users/strCarne/Documents/Projects/C++/snake-game/build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/strCarne/Documents/Projects/C++/snake-game /Users/strCarne/Documents/Projects/C++/snake-game/objects /Users/strCarne/Documents/Projects/C++/snake-game/build-release /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects /Users/strCarne/Documents/Projects/C++/snake-game/build-release/objects/CMakeFiles/objects.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : objects/CMakeFiles/objects.dir/depend

