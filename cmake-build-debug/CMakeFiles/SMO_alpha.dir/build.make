# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Vladimir\CLionProjects\SMO_alpha

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Vladimir\CLionProjects\SMO_alpha\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SMO_alpha.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SMO_alpha.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SMO_alpha.dir/flags.make

CMakeFiles/SMO_alpha.dir/main.cpp.obj: CMakeFiles/SMO_alpha.dir/flags.make
CMakeFiles/SMO_alpha.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Vladimir\CLionProjects\SMO_alpha\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SMO_alpha.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SMO_alpha.dir\main.cpp.obj -c C:\Users\Vladimir\CLionProjects\SMO_alpha\main.cpp

CMakeFiles/SMO_alpha.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SMO_alpha.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Vladimir\CLionProjects\SMO_alpha\main.cpp > CMakeFiles\SMO_alpha.dir\main.cpp.i

CMakeFiles/SMO_alpha.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SMO_alpha.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Vladimir\CLionProjects\SMO_alpha\main.cpp -o CMakeFiles\SMO_alpha.dir\main.cpp.s

CMakeFiles/SMO_alpha.dir/QueuingSystem.cpp.obj: CMakeFiles/SMO_alpha.dir/flags.make
CMakeFiles/SMO_alpha.dir/QueuingSystem.cpp.obj: ../QueuingSystem.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Vladimir\CLionProjects\SMO_alpha\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SMO_alpha.dir/QueuingSystem.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SMO_alpha.dir\QueuingSystem.cpp.obj -c C:\Users\Vladimir\CLionProjects\SMO_alpha\QueuingSystem.cpp

CMakeFiles/SMO_alpha.dir/QueuingSystem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SMO_alpha.dir/QueuingSystem.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Vladimir\CLionProjects\SMO_alpha\QueuingSystem.cpp > CMakeFiles\SMO_alpha.dir\QueuingSystem.cpp.i

CMakeFiles/SMO_alpha.dir/QueuingSystem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SMO_alpha.dir/QueuingSystem.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Vladimir\CLionProjects\SMO_alpha\QueuingSystem.cpp -o CMakeFiles\SMO_alpha.dir\QueuingSystem.cpp.s

# Object files for target SMO_alpha
SMO_alpha_OBJECTS = \
"CMakeFiles/SMO_alpha.dir/main.cpp.obj" \
"CMakeFiles/SMO_alpha.dir/QueuingSystem.cpp.obj"

# External object files for target SMO_alpha
SMO_alpha_EXTERNAL_OBJECTS =

SMO_alpha.exe: CMakeFiles/SMO_alpha.dir/main.cpp.obj
SMO_alpha.exe: CMakeFiles/SMO_alpha.dir/QueuingSystem.cpp.obj
SMO_alpha.exe: CMakeFiles/SMO_alpha.dir/build.make
SMO_alpha.exe: CMakeFiles/SMO_alpha.dir/linklibs.rsp
SMO_alpha.exe: CMakeFiles/SMO_alpha.dir/objects1.rsp
SMO_alpha.exe: CMakeFiles/SMO_alpha.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Vladimir\CLionProjects\SMO_alpha\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable SMO_alpha.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\SMO_alpha.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SMO_alpha.dir/build: SMO_alpha.exe

.PHONY : CMakeFiles/SMO_alpha.dir/build

CMakeFiles/SMO_alpha.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SMO_alpha.dir\cmake_clean.cmake
.PHONY : CMakeFiles/SMO_alpha.dir/clean

CMakeFiles/SMO_alpha.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Vladimir\CLionProjects\SMO_alpha C:\Users\Vladimir\CLionProjects\SMO_alpha C:\Users\Vladimir\CLionProjects\SMO_alpha\cmake-build-debug C:\Users\Vladimir\CLionProjects\SMO_alpha\cmake-build-debug C:\Users\Vladimir\CLionProjects\SMO_alpha\cmake-build-debug\CMakeFiles\SMO_alpha.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SMO_alpha.dir/depend

