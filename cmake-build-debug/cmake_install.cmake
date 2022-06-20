<<<<<<< HEAD
# Install script for directory: C:/Studia/STUDIA_2a/main_last_project/ZPO/NetSim
=======
# Install script for directory: E:/ZPO/NetSim
>>>>>>> edbc1e6bce8802816b63b5c93ffd122166a579f7

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/NetSim")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/msys64/mingw64/bin/objdump.exe")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
<<<<<<< HEAD
  include("C:/Studia/STUDIA_2a/main_last_project/ZPO/NetSim/cmake-build-debug/googletest-master/cmake_install.cmake")
=======
  include("E:/ZPO/NetSim/cmake-build-debug/googletest-master/cmake_install.cmake")
>>>>>>> edbc1e6bce8802816b63b5c93ffd122166a579f7
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
<<<<<<< HEAD
file(WRITE "C:/Studia/STUDIA_2a/main_last_project/ZPO/NetSim/cmake-build-debug/${CMAKE_INSTALL_MANIFEST}"
=======
file(WRITE "E:/ZPO/NetSim/cmake-build-debug/${CMAKE_INSTALL_MANIFEST}"
>>>>>>> edbc1e6bce8802816b63b5c93ffd122166a579f7
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
