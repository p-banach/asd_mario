# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files (x86)\CLion\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\CLion\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Patryk\Documents\code\repos\mario2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Patryk\Documents\code\repos\mario2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/mario2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mario2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mario2.dir/flags.make

CMakeFiles/mario2.dir/main.cpp.obj: CMakeFiles/mario2.dir/flags.make
CMakeFiles/mario2.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Patryk\Documents\code\repos\mario2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mario2.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\mario2.dir\main.cpp.obj -c C:\Users\Patryk\Documents\code\repos\mario2\main.cpp

CMakeFiles/mario2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mario2.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Patryk\Documents\code\repos\mario2\main.cpp > CMakeFiles\mario2.dir\main.cpp.i

CMakeFiles/mario2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mario2.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Patryk\Documents\code\repos\mario2\main.cpp -o CMakeFiles\mario2.dir\main.cpp.s

CMakeFiles/mario2.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/mario2.dir/main.cpp.obj.requires

CMakeFiles/mario2.dir/main.cpp.obj.provides: CMakeFiles/mario2.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\mario2.dir\build.make CMakeFiles/mario2.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/mario2.dir/main.cpp.obj.provides

CMakeFiles/mario2.dir/main.cpp.obj.provides.build: CMakeFiles/mario2.dir/main.cpp.obj


# Object files for target mario2
mario2_OBJECTS = \
"CMakeFiles/mario2.dir/main.cpp.obj"

# External object files for target mario2
mario2_EXTERNAL_OBJECTS =

mario2.exe: CMakeFiles/mario2.dir/main.cpp.obj
mario2.exe: CMakeFiles/mario2.dir/build.make
mario2.exe: CMakeFiles/mario2.dir/linklibs.rsp
mario2.exe: CMakeFiles/mario2.dir/objects1.rsp
mario2.exe: CMakeFiles/mario2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Patryk\Documents\code\repos\mario2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable mario2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\mario2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mario2.dir/build: mario2.exe

.PHONY : CMakeFiles/mario2.dir/build

CMakeFiles/mario2.dir/requires: CMakeFiles/mario2.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/mario2.dir/requires

CMakeFiles/mario2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\mario2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/mario2.dir/clean

CMakeFiles/mario2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Patryk\Documents\code\repos\mario2 C:\Users\Patryk\Documents\code\repos\mario2 C:\Users\Patryk\Documents\code\repos\mario2\cmake-build-debug C:\Users\Patryk\Documents\code\repos\mario2\cmake-build-debug C:\Users\Patryk\Documents\code\repos\mario2\cmake-build-debug\CMakeFiles\mario2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mario2.dir/depend

