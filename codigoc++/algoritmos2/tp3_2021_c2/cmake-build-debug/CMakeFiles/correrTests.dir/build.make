# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/imac/Documents/GitHub2/programas-algoritmos/tp3_2021_c2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/imac/Documents/GitHub2/programas-algoritmos/tp3_2021_c2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/correrTests.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/correrTests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/correrTests.dir/flags.make

CMakeFiles/correrTests.dir/src/aed2_mapa.cpp.o: CMakeFiles/correrTests.dir/flags.make
CMakeFiles/correrTests.dir/src/aed2_mapa.cpp.o: ../src/aed2_mapa.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/imac/Documents/GitHub2/programas-algoritmos/tp3_2021_c2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/correrTests.dir/src/aed2_mapa.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/correrTests.dir/src/aed2_mapa.cpp.o -c /Users/imac/Documents/GitHub2/programas-algoritmos/tp3_2021_c2/src/aed2_mapa.cpp

CMakeFiles/correrTests.dir/src/aed2_mapa.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/correrTests.dir/src/aed2_mapa.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/imac/Documents/GitHub2/programas-algoritmos/tp3_2021_c2/src/aed2_mapa.cpp > CMakeFiles/correrTests.dir/src/aed2_mapa.cpp.i

CMakeFiles/correrTests.dir/src/aed2_mapa.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/correrTests.dir/src/aed2_mapa.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/imac/Documents/GitHub2/programas-algoritmos/tp3_2021_c2/src/aed2_mapa.cpp -o CMakeFiles/correrTests.dir/src/aed2_mapa.cpp.s

CMakeFiles/correrTests.dir/src/aed2_simulacion.cpp.o: CMakeFiles/correrTests.dir/flags.make
CMakeFiles/correrTests.dir/src/aed2_simulacion.cpp.o: ../src/aed2_simulacion.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/imac/Documents/GitHub2/programas-algoritmos/tp3_2021_c2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/correrTests.dir/src/aed2_simulacion.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/correrTests.dir/src/aed2_simulacion.cpp.o -c /Users/imac/Documents/GitHub2/programas-algoritmos/tp3_2021_c2/src/aed2_simulacion.cpp

CMakeFiles/correrTests.dir/src/aed2_simulacion.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/correrTests.dir/src/aed2_simulacion.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/imac/Documents/GitHub2/programas-algoritmos/tp3_2021_c2/src/aed2_simulacion.cpp > CMakeFiles/correrTests.dir/src/aed2_simulacion.cpp.i

CMakeFiles/correrTests.dir/src/aed2_simulacion.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/correrTests.dir/src/aed2_simulacion.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/imac/Documents/GitHub2/programas-algoritmos/tp3_2021_c2/src/aed2_simulacion.cpp -o CMakeFiles/correrTests.dir/src/aed2_simulacion.cpp.s

CMakeFiles/correrTests.dir/src/mapa.cpp.o: CMakeFiles/correrTests.dir/flags.make
CMakeFiles/correrTests.dir/src/mapa.cpp.o: ../src/mapa.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/imac/Documents/GitHub2/programas-algoritmos/tp3_2021_c2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/correrTests.dir/src/mapa.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/correrTests.dir/src/mapa.cpp.o -c /Users/imac/Documents/GitHub2/programas-algoritmos/tp3_2021_c2/src/mapa.cpp

CMakeFiles/correrTests.dir/src/mapa.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/correrTests.dir/src/mapa.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/imac/Documents/GitHub2/programas-algoritmos/tp3_2021_c2/src/mapa.cpp > CMakeFiles/correrTests.dir/src/mapa.cpp.i

CMakeFiles/correrTests.dir/src/mapa.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/correrTests.dir/src/mapa.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/imac/Documents/GitHub2/programas-algoritmos/tp3_2021_c2/src/mapa.cpp -o CMakeFiles/correrTests.dir/src/mapa.cpp.s

CMakeFiles/correrTests.dir/src/objetivo.cpp.o: CMakeFiles/correrTests.dir/flags.make
CMakeFiles/correrTests.dir/src/objetivo.cpp.o: ../src/objetivo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/imac/Documents/GitHub2/programas-algoritmos/tp3_2021_c2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/correrTests.dir/src/objetivo.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/correrTests.dir/src/objetivo.cpp.o -c /Users/imac/Documents/GitHub2/programas-algoritmos/tp3_2021_c2/src/objetivo.cpp

CMakeFiles/correrTests.dir/src/objetivo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/correrTests.dir/src/objetivo.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/imac/Documents/GitHub2/programas-algoritmos/tp3_2021_c2/src/objetivo.cpp > CMakeFiles/correrTests.dir/src/objetivo.cpp.i

CMakeFiles/correrTests.dir/src/objetivo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/correrTests.dir/src/objetivo.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/imac/Documents/GitHub2/programas-algoritmos/tp3_2021_c2/src/objetivo.cpp -o CMakeFiles/correrTests.dir/src/objetivo.cpp.s

CMakeFiles/correrTests.dir/src/simulacion.cpp.o: CMakeFiles/correrTests.dir/flags.make
CMakeFiles/correrTests.dir/src/simulacion.cpp.o: ../src/simulacion.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/imac/Documents/GitHub2/programas-algoritmos/tp3_2021_c2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/correrTests.dir/src/simulacion.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/correrTests.dir/src/simulacion.cpp.o -c /Users/imac/Documents/GitHub2/programas-algoritmos/tp3_2021_c2/src/simulacion.cpp

CMakeFiles/correrTests.dir/src/simulacion.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/correrTests.dir/src/simulacion.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/imac/Documents/GitHub2/programas-algoritmos/tp3_2021_c2/src/simulacion.cpp > CMakeFiles/correrTests.dir/src/simulacion.cpp.i

CMakeFiles/correrTests.dir/src/simulacion.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/correrTests.dir/src/simulacion.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/imac/Documents/GitHub2/programas-algoritmos/tp3_2021_c2/src/simulacion.cpp -o CMakeFiles/correrTests.dir/src/simulacion.cpp.s

CMakeFiles/correrTests.dir/tests/simulacion-tests.cpp.o: CMakeFiles/correrTests.dir/flags.make
CMakeFiles/correrTests.dir/tests/simulacion-tests.cpp.o: ../tests/simulacion-tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/imac/Documents/GitHub2/programas-algoritmos/tp3_2021_c2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/correrTests.dir/tests/simulacion-tests.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/correrTests.dir/tests/simulacion-tests.cpp.o -c /Users/imac/Documents/GitHub2/programas-algoritmos/tp3_2021_c2/tests/simulacion-tests.cpp

CMakeFiles/correrTests.dir/tests/simulacion-tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/correrTests.dir/tests/simulacion-tests.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/imac/Documents/GitHub2/programas-algoritmos/tp3_2021_c2/tests/simulacion-tests.cpp > CMakeFiles/correrTests.dir/tests/simulacion-tests.cpp.i

CMakeFiles/correrTests.dir/tests/simulacion-tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/correrTests.dir/tests/simulacion-tests.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/imac/Documents/GitHub2/programas-algoritmos/tp3_2021_c2/tests/simulacion-tests.cpp -o CMakeFiles/correrTests.dir/tests/simulacion-tests.cpp.s

# Object files for target correrTests
correrTests_OBJECTS = \
"CMakeFiles/correrTests.dir/src/aed2_mapa.cpp.o" \
"CMakeFiles/correrTests.dir/src/aed2_simulacion.cpp.o" \
"CMakeFiles/correrTests.dir/src/mapa.cpp.o" \
"CMakeFiles/correrTests.dir/src/objetivo.cpp.o" \
"CMakeFiles/correrTests.dir/src/simulacion.cpp.o" \
"CMakeFiles/correrTests.dir/tests/simulacion-tests.cpp.o"

# External object files for target correrTests
correrTests_EXTERNAL_OBJECTS =

correrTests: CMakeFiles/correrTests.dir/src/aed2_mapa.cpp.o
correrTests: CMakeFiles/correrTests.dir/src/aed2_simulacion.cpp.o
correrTests: CMakeFiles/correrTests.dir/src/mapa.cpp.o
correrTests: CMakeFiles/correrTests.dir/src/objetivo.cpp.o
correrTests: CMakeFiles/correrTests.dir/src/simulacion.cpp.o
correrTests: CMakeFiles/correrTests.dir/tests/simulacion-tests.cpp.o
correrTests: CMakeFiles/correrTests.dir/build.make
correrTests: libgtest.a
correrTests: libgtest_main.a
correrTests: CMakeFiles/correrTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/imac/Documents/GitHub2/programas-algoritmos/tp3_2021_c2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable correrTests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/correrTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/correrTests.dir/build: correrTests
.PHONY : CMakeFiles/correrTests.dir/build

CMakeFiles/correrTests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/correrTests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/correrTests.dir/clean

CMakeFiles/correrTests.dir/depend:
	cd /Users/imac/Documents/GitHub2/programas-algoritmos/tp3_2021_c2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/imac/Documents/GitHub2/programas-algoritmos/tp3_2021_c2 /Users/imac/Documents/GitHub2/programas-algoritmos/tp3_2021_c2 /Users/imac/Documents/GitHub2/programas-algoritmos/tp3_2021_c2/cmake-build-debug /Users/imac/Documents/GitHub2/programas-algoritmos/tp3_2021_c2/cmake-build-debug /Users/imac/Documents/GitHub2/programas-algoritmos/tp3_2021_c2/cmake-build-debug/CMakeFiles/correrTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/correrTests.dir/depend
