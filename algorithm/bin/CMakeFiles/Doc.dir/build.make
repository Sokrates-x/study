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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sokrates/work/algorithm/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sokrates/work/algorithm/bin

# Include any dependencies generated for this target.
include CMakeFiles/Doc.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Doc.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Doc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Doc.dir/flags.make

CMakeFiles/Doc.dir/doc.cxx.o: CMakeFiles/Doc.dir/flags.make
CMakeFiles/Doc.dir/doc.cxx.o: /home/sokrates/work/algorithm/src/doc.cxx
CMakeFiles/Doc.dir/doc.cxx.o: CMakeFiles/Doc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sokrates/work/algorithm/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Doc.dir/doc.cxx.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Doc.dir/doc.cxx.o -MF CMakeFiles/Doc.dir/doc.cxx.o.d -o CMakeFiles/Doc.dir/doc.cxx.o -c /home/sokrates/work/algorithm/src/doc.cxx

CMakeFiles/Doc.dir/doc.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Doc.dir/doc.cxx.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sokrates/work/algorithm/src/doc.cxx > CMakeFiles/Doc.dir/doc.cxx.i

CMakeFiles/Doc.dir/doc.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Doc.dir/doc.cxx.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sokrates/work/algorithm/src/doc.cxx -o CMakeFiles/Doc.dir/doc.cxx.s

# Object files for target Doc
Doc_OBJECTS = \
"CMakeFiles/Doc.dir/doc.cxx.o"

# External object files for target Doc
Doc_EXTERNAL_OBJECTS =

Doc: CMakeFiles/Doc.dir/doc.cxx.o
Doc: CMakeFiles/Doc.dir/build.make
Doc: CMakeFiles/Doc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sokrates/work/algorithm/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Doc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Doc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Doc.dir/build: Doc
.PHONY : CMakeFiles/Doc.dir/build

CMakeFiles/Doc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Doc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Doc.dir/clean

CMakeFiles/Doc.dir/depend:
	cd /home/sokrates/work/algorithm/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sokrates/work/algorithm/src /home/sokrates/work/algorithm/src /home/sokrates/work/algorithm/bin /home/sokrates/work/algorithm/bin /home/sokrates/work/algorithm/bin/CMakeFiles/Doc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Doc.dir/depend

