# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = "D:\CLion 2017.3.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2017.3.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\!!Studia\Semestr II\C++\lab6 - szablon"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\!!Studia\Semestr II\C++\lab6 - szablon\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/lab6__.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab6__.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab6__.dir/flags.make

CMakeFiles/lab6__.dir/main.cpp.obj: CMakeFiles/lab6__.dir/flags.make
CMakeFiles/lab6__.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\!!Studia\Semestr II\C++\lab6 - szablon\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab6__.dir/main.cpp.obj"
	D:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\lab6__.dir\main.cpp.obj -c "D:\!!Studia\Semestr II\C++\lab6 - szablon\main.cpp"

CMakeFiles/lab6__.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab6__.dir/main.cpp.i"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\!!Studia\Semestr II\C++\lab6 - szablon\main.cpp" > CMakeFiles\lab6__.dir\main.cpp.i

CMakeFiles/lab6__.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab6__.dir/main.cpp.s"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\!!Studia\Semestr II\C++\lab6 - szablon\main.cpp" -o CMakeFiles\lab6__.dir\main.cpp.s

CMakeFiles/lab6__.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/lab6__.dir/main.cpp.obj.requires

CMakeFiles/lab6__.dir/main.cpp.obj.provides: CMakeFiles/lab6__.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\lab6__.dir\build.make CMakeFiles/lab6__.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/lab6__.dir/main.cpp.obj.provides

CMakeFiles/lab6__.dir/main.cpp.obj.provides.build: CMakeFiles/lab6__.dir/main.cpp.obj


# Object files for target lab6__
lab6___OBJECTS = \
"CMakeFiles/lab6__.dir/main.cpp.obj"

# External object files for target lab6__
lab6___EXTERNAL_OBJECTS =

lab6__.exe: CMakeFiles/lab6__.dir/main.cpp.obj
lab6__.exe: CMakeFiles/lab6__.dir/build.make
lab6__.exe: CMakeFiles/lab6__.dir/linklibs.rsp
lab6__.exe: CMakeFiles/lab6__.dir/objects1.rsp
lab6__.exe: CMakeFiles/lab6__.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\!!Studia\Semestr II\C++\lab6 - szablon\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lab6__.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\lab6__.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab6__.dir/build: lab6__.exe

.PHONY : CMakeFiles/lab6__.dir/build

CMakeFiles/lab6__.dir/requires: CMakeFiles/lab6__.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/lab6__.dir/requires

CMakeFiles/lab6__.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\lab6__.dir\cmake_clean.cmake
.PHONY : CMakeFiles/lab6__.dir/clean

CMakeFiles/lab6__.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\!!Studia\Semestr II\C++\lab6 - szablon" "D:\!!Studia\Semestr II\C++\lab6 - szablon" "D:\!!Studia\Semestr II\C++\lab6 - szablon\cmake-build-debug" "D:\!!Studia\Semestr II\C++\lab6 - szablon\cmake-build-debug" "D:\!!Studia\Semestr II\C++\lab6 - szablon\cmake-build-debug\CMakeFiles\lab6__.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/lab6__.dir/depend
