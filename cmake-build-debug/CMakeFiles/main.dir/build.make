# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Jason\Documents\CS211\compsci-211-final

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Jason\Documents\CS211\compsci-211-final\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/src/main.cxx.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/main.cxx.obj: CMakeFiles/main.dir/includes_CXX.rsp
CMakeFiles/main.dir/src/main.cxx.obj: ../src/main.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Jason\Documents\CS211\compsci-211-final\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/src/main.cxx.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\main.dir\src\main.cxx.obj -c C:\Users\Jason\Documents\CS211\compsci-211-final\src\main.cxx

CMakeFiles/main.dir/src/main.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/main.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Jason\Documents\CS211\compsci-211-final\src\main.cxx > CMakeFiles\main.dir\src\main.cxx.i

CMakeFiles/main.dir/src/main.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/main.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Jason\Documents\CS211\compsci-211-final\src\main.cxx -o CMakeFiles\main.dir\src\main.cxx.s

CMakeFiles/main.dir/src/controller.cxx.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/controller.cxx.obj: CMakeFiles/main.dir/includes_CXX.rsp
CMakeFiles/main.dir/src/controller.cxx.obj: ../src/controller.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Jason\Documents\CS211\compsci-211-final\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.dir/src/controller.cxx.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\main.dir\src\controller.cxx.obj -c C:\Users\Jason\Documents\CS211\compsci-211-final\src\controller.cxx

CMakeFiles/main.dir/src/controller.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/controller.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Jason\Documents\CS211\compsci-211-final\src\controller.cxx > CMakeFiles\main.dir\src\controller.cxx.i

CMakeFiles/main.dir/src/controller.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/controller.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Jason\Documents\CS211\compsci-211-final\src\controller.cxx -o CMakeFiles\main.dir\src\controller.cxx.s

CMakeFiles/main.dir/src/player.cxx.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/player.cxx.obj: CMakeFiles/main.dir/includes_CXX.rsp
CMakeFiles/main.dir/src/player.cxx.obj: ../src/player.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Jason\Documents\CS211\compsci-211-final\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.dir/src/player.cxx.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\main.dir\src\player.cxx.obj -c C:\Users\Jason\Documents\CS211\compsci-211-final\src\player.cxx

CMakeFiles/main.dir/src/player.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/player.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Jason\Documents\CS211\compsci-211-final\src\player.cxx > CMakeFiles\main.dir\src\player.cxx.i

CMakeFiles/main.dir/src/player.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/player.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Jason\Documents\CS211\compsci-211-final\src\player.cxx -o CMakeFiles\main.dir\src\player.cxx.s

CMakeFiles/main.dir/src/view.cxx.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/view.cxx.obj: CMakeFiles/main.dir/includes_CXX.rsp
CMakeFiles/main.dir/src/view.cxx.obj: ../src/view.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Jason\Documents\CS211\compsci-211-final\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main.dir/src/view.cxx.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\main.dir\src\view.cxx.obj -c C:\Users\Jason\Documents\CS211\compsci-211-final\src\view.cxx

CMakeFiles/main.dir/src/view.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/view.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Jason\Documents\CS211\compsci-211-final\src\view.cxx > CMakeFiles\main.dir\src\view.cxx.i

CMakeFiles/main.dir/src/view.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/view.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Jason\Documents\CS211\compsci-211-final\src\view.cxx -o CMakeFiles\main.dir\src\view.cxx.s

CMakeFiles/main.dir/src/model.cxx.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/model.cxx.obj: CMakeFiles/main.dir/includes_CXX.rsp
CMakeFiles/main.dir/src/model.cxx.obj: ../src/model.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Jason\Documents\CS211\compsci-211-final\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/main.dir/src/model.cxx.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\main.dir\src\model.cxx.obj -c C:\Users\Jason\Documents\CS211\compsci-211-final\src\model.cxx

CMakeFiles/main.dir/src/model.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/model.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Jason\Documents\CS211\compsci-211-final\src\model.cxx > CMakeFiles\main.dir\src\model.cxx.i

CMakeFiles/main.dir/src/model.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/model.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Jason\Documents\CS211\compsci-211-final\src\model.cxx -o CMakeFiles\main.dir\src\model.cxx.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/src/main.cxx.obj" \
"CMakeFiles/main.dir/src/controller.cxx.obj" \
"CMakeFiles/main.dir/src/player.cxx.obj" \
"CMakeFiles/main.dir/src/view.cxx.obj" \
"CMakeFiles/main.dir/src/model.cxx.obj"

# External object files for target main
main_EXTERNAL_OBJECTS =

main.exe: CMakeFiles/main.dir/src/main.cxx.obj
main.exe: CMakeFiles/main.dir/src/controller.cxx.obj
main.exe: CMakeFiles/main.dir/src/player.cxx.obj
main.exe: CMakeFiles/main.dir/src/view.cxx.obj
main.exe: CMakeFiles/main.dir/src/model.cxx.obj
main.exe: CMakeFiles/main.dir/build.make
main.exe: .cs211/lib/ge211/libge211.a
main.exe: C:/MinGW/lib/libSDL2main.a
main.exe: C:/MinGW/lib/libSDL2.dll.a
main.exe: C:/MinGW/lib/libSDL2_image.dll.a
main.exe: C:/MinGW/lib/libSDL2_mixer.dll.a
main.exe: C:/MinGW/lib/libSDL2_ttf.dll.a
main.exe: CMakeFiles/main.dir/linklibs.rsp
main.exe: CMakeFiles/main.dir/objects1.rsp
main.exe: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Jason\Documents\CS211\compsci-211-final\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable main.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\main.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main.exe

.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\main.dir\cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Jason\Documents\CS211\compsci-211-final C:\Users\Jason\Documents\CS211\compsci-211-final C:\Users\Jason\Documents\CS211\compsci-211-final\cmake-build-debug C:\Users\Jason\Documents\CS211\compsci-211-final\cmake-build-debug C:\Users\Jason\Documents\CS211\compsci-211-final\cmake-build-debug\CMakeFiles\main.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend
