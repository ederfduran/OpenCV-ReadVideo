# OpenCV-ReadVideo

**TOOL SET:**

* macOS Mojave
* CMake and Make (Build Project)
* vsCode (Editor)
* lldb (Debug, https://code.visualstudio.com/docs/cpp/config-clang-mac)
* vcpkg (Package Manager, https://github.com/microsoft/vcpkg)

# Description 

This is a very simple project to show some basic functionality of OpenCV.
* Read a video file and show it in a window. 

There are some important things to notice here:

* /vscode is a folder generetaed by vsCode to set up the debug functionality.Also has a c_cpp_properties.json to help the intell¡sense to find the headers files. (https://code.visualstudio.com/docs/cpp/c-cpp-properties-schema-reference)
* CMakeLists.txt used to build the project. Notice i use vcpkg to bind OpenCV library.
* small.mov is a very small video file to test purpose

# Steps to run

On Project folder :

```sh
$ mkdir build && cd build
$ cmake ..
$ make
$ ./Read_Video <path to video file> // For this example : ./Read_Video ../small.mov
```
