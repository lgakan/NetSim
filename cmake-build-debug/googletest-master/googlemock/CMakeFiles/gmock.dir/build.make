# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
<<<<<<< HEAD
CMAKE_SOURCE_DIR = C:\Studia\STUDIA_2a\main_last_project\ZPO\NetSim

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Studia\STUDIA_2a\main_last_project\ZPO\NetSim\cmake-build-debug
=======
CMAKE_SOURCE_DIR = E:\ZPO\NetSim

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\ZPO\NetSim\cmake-build-debug
>>>>>>> edbc1e6bce8802816b63b5c93ffd122166a579f7

# Include any dependencies generated for this target.
include googletest-master/googlemock/CMakeFiles/gmock.dir/depend.make
# Include the progress variables for this target.
include googletest-master/googlemock/CMakeFiles/gmock.dir/progress.make

# Include the compile flags for this target's objects.
include googletest-master/googlemock/CMakeFiles/gmock.dir/flags.make

googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.obj: googletest-master/googlemock/CMakeFiles/gmock.dir/flags.make
googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.obj: googletest-master/googlemock/CMakeFiles/gmock.dir/includes_CXX.rsp
googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.obj: ../googletest-master/googlemock/src/gmock-all.cc
<<<<<<< HEAD
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Studia\STUDIA_2a\main_last_project\ZPO\NetSim\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.obj"
	cd /d C:\Studia\STUDIA_2a\main_last_project\ZPO\NetSim\cmake-build-debug\googletest-master\googlemock && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\gmock.dir\src\gmock-all.cc.obj -c C:\Studia\STUDIA_2a\main_last_project\ZPO\NetSim\googletest-master\googlemock\src\gmock-all.cc

googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock.dir/src/gmock-all.cc.i"
	cd /d C:\Studia\STUDIA_2a\main_last_project\ZPO\NetSim\cmake-build-debug\googletest-master\googlemock && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Studia\STUDIA_2a\main_last_project\ZPO\NetSim\googletest-master\googlemock\src\gmock-all.cc > CMakeFiles\gmock.dir\src\gmock-all.cc.i

googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock.dir/src/gmock-all.cc.s"
	cd /d C:\Studia\STUDIA_2a\main_last_project\ZPO\NetSim\cmake-build-debug\googletest-master\googlemock && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Studia\STUDIA_2a\main_last_project\ZPO\NetSim\googletest-master\googlemock\src\gmock-all.cc -o CMakeFiles\gmock.dir\src\gmock-all.cc.s
=======
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\ZPO\NetSim\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.obj"
	cd /d E:\ZPO\NetSim\cmake-build-debug\googletest-master\googlemock && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\gmock.dir\src\gmock-all.cc.obj -c E:\ZPO\NetSim\googletest-master\googlemock\src\gmock-all.cc

googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock.dir/src/gmock-all.cc.i"
	cd /d E:\ZPO\NetSim\cmake-build-debug\googletest-master\googlemock && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\ZPO\NetSim\googletest-master\googlemock\src\gmock-all.cc > CMakeFiles\gmock.dir\src\gmock-all.cc.i

googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock.dir/src/gmock-all.cc.s"
	cd /d E:\ZPO\NetSim\cmake-build-debug\googletest-master\googlemock && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\ZPO\NetSim\googletest-master\googlemock\src\gmock-all.cc -o CMakeFiles\gmock.dir\src\gmock-all.cc.s
>>>>>>> edbc1e6bce8802816b63b5c93ffd122166a579f7

# Object files for target gmock
gmock_OBJECTS = \
"CMakeFiles/gmock.dir/src/gmock-all.cc.obj"

# External object files for target gmock
gmock_EXTERNAL_OBJECTS =

lib/libgmockd.a: googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.obj
lib/libgmockd.a: googletest-master/googlemock/CMakeFiles/gmock.dir/build.make
lib/libgmockd.a: googletest-master/googlemock/CMakeFiles/gmock.dir/link.txt
<<<<<<< HEAD
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Studia\STUDIA_2a\main_last_project\ZPO\NetSim\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ..\..\lib\libgmockd.a"
	cd /d C:\Studia\STUDIA_2a\main_last_project\ZPO\NetSim\cmake-build-debug\googletest-master\googlemock && $(CMAKE_COMMAND) -P CMakeFiles\gmock.dir\cmake_clean_target.cmake
	cd /d C:\Studia\STUDIA_2a\main_last_project\ZPO\NetSim\cmake-build-debug\googletest-master\googlemock && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\gmock.dir\link.txt --verbose=$(VERBOSE)
=======
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\ZPO\NetSim\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ..\..\lib\libgmockd.a"
	cd /d E:\ZPO\NetSim\cmake-build-debug\googletest-master\googlemock && $(CMAKE_COMMAND) -P CMakeFiles\gmock.dir\cmake_clean_target.cmake
	cd /d E:\ZPO\NetSim\cmake-build-debug\googletest-master\googlemock && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\gmock.dir\link.txt --verbose=$(VERBOSE)
>>>>>>> edbc1e6bce8802816b63b5c93ffd122166a579f7

# Rule to build all files generated by this target.
googletest-master/googlemock/CMakeFiles/gmock.dir/build: lib/libgmockd.a
.PHONY : googletest-master/googlemock/CMakeFiles/gmock.dir/build

googletest-master/googlemock/CMakeFiles/gmock.dir/clean:
<<<<<<< HEAD
	cd /d C:\Studia\STUDIA_2a\main_last_project\ZPO\NetSim\cmake-build-debug\googletest-master\googlemock && $(CMAKE_COMMAND) -P CMakeFiles\gmock.dir\cmake_clean.cmake
.PHONY : googletest-master/googlemock/CMakeFiles/gmock.dir/clean

googletest-master/googlemock/CMakeFiles/gmock.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Studia\STUDIA_2a\main_last_project\ZPO\NetSim C:\Studia\STUDIA_2a\main_last_project\ZPO\NetSim\googletest-master\googlemock C:\Studia\STUDIA_2a\main_last_project\ZPO\NetSim\cmake-build-debug C:\Studia\STUDIA_2a\main_last_project\ZPO\NetSim\cmake-build-debug\googletest-master\googlemock C:\Studia\STUDIA_2a\main_last_project\ZPO\NetSim\cmake-build-debug\googletest-master\googlemock\CMakeFiles\gmock.dir\DependInfo.cmake --color=$(COLOR)
=======
	cd /d E:\ZPO\NetSim\cmake-build-debug\googletest-master\googlemock && $(CMAKE_COMMAND) -P CMakeFiles\gmock.dir\cmake_clean.cmake
.PHONY : googletest-master/googlemock/CMakeFiles/gmock.dir/clean

googletest-master/googlemock/CMakeFiles/gmock.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\ZPO\NetSim E:\ZPO\NetSim\googletest-master\googlemock E:\ZPO\NetSim\cmake-build-debug E:\ZPO\NetSim\cmake-build-debug\googletest-master\googlemock E:\ZPO\NetSim\cmake-build-debug\googletest-master\googlemock\CMakeFiles\gmock.dir\DependInfo.cmake --color=$(COLOR)
>>>>>>> edbc1e6bce8802816b63b5c93ffd122166a579f7
.PHONY : googletest-master/googlemock/CMakeFiles/gmock.dir/depend

