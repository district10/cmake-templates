To c++/cmake users:

-    It's much better to bind your c++ code to python, then test/debug in python side
-    I would recommend <https://github.com/pybind/scikit_build_example>
    - or my small binding repos: [concave-hull](https://github.com/cubao/concave_hull), [pixelmatch](https://github.com/cubao/pybind11_pixelmatch)
-    This repo is old, for modern cmake, see: <https://cliutils.gitlab.io/modern-cmake> ([中文版本](https://modern-cmake-cn.github.io/Modern-CMake-zh_CN/))


---

# cmake-templates

Some CMake Templates.

## 1. Overview

**Conventions**

-   :smile: means tested okay/good
-   :rage: means test result not sufficiently good
-   :question: means not tested yet

| Project                       | Linux + GCC 4.8+ | Win + VS2010 | Win + VS2015 | macOS   |
| :---------------------------: | :--------------: | :----------: | :----------: | :---:   |
| [c][refc]                     | :smile:          |  :smile:     | :smile:      | :smile: |
| [c++][refcpp]                 | :smile:          |  :smile:     | :smile:      | :smile: |
| [c++11][refcpp11]             | :smile:          |  :rage:      | :smile:      | :smile: |
| [c++11vs2010][refcpp11vs2010] | :smile:          |  :smile:     | :smile:      | :smile: |
| [module][refmodule]           | :smile:          |  :smile:     | :smile:      | :smile: |
| [opencv][refocv]              | :question:       |  :smile:     | :question:   | :rage:  |
| [opencv3][refocv3]            | :smile:          |  :question:  | :smile:      | :smile: |
| [boost][refboost]             | :smile:          |  :smile:     | :question:   | :smile: |
| [qt4-console][refqt4c]        | :smile:          |  :smile:     | :smile:      | :rage:  |
| [qt4-gui][refqt4g]            | :smile:          |  :smile:     | :smile:      | :rage:  |
| [qt4-project][refqt4p]        | :smile:          |  :smile:     | :smile:      | :rage:  |
| [qt5-project][refqt5p]        | :smile:          |  :question:  | :smile:      | :smile: |


[refc]: #31-c-example
[refcpp]: #32-c-example
[refcpp11]: #33-c11-example
[refcpp11vs2010]: #33-c11-example
[refmodule]: #34-example-to-show-how-to-modualize-your-project
[refboost]: #35-example-with-support-of-boost
[refocv]: #36-example-with-support-of-opencv
[refocv3]: #36-example-with-support-of-opencv
[refqt4c]: #37-example-with-support-of-qt4
[refqt4g]: #37-example-with-support-of-qt4
[refqt4p]: #37-example-with-support-of-qt4
[refqt5p]: #38-example-with-support-of-qt5

## 2. Usage

### 2.1. Windows

Use `CMake-GUI` to generate Visual Studio 2010 project, then use Visual Studio to compile & run.

Here is a Tutorial: [HOWTO: Win + CMake + Visual Studio 2010 · Issue #1 · district10/cmake-templates](https://github.com/district10/cmake-templates/issues/1).

### 2.2. Linux

Most commonly, we build Makefile project:

```bash
# cd source dir (there should be a CMakeLists.txt)
mkdir build && cd build
cmake ..            # want a release build? try `cmake -DCMAKE_BUILD_TYPE=Release ..'
make

# then checkout the generated binary files
```

But we can build CodeBlocks projects too, see my tutorial:
[HOWTO: Linux + CMake + CodeBlocks + GNU Make · Issue #2 · district10/cmake-templates](https://github.com/district10/cmake-templates/issues/2),
or use qt-creator to open CMakeLists.txt directly, see my tutorial:
[HOWTO: Use Qt creator to Open CMakeLists.txt directly (will generate proper project files) · Issue #5 · district10/cmake-templates](https://github.com/district10/cmake-templates/issues/5).

## 3. Examples

### 3.1. C Example

Simple C project.

```cmake
project( C )
cmake_minimum_required( VERSION 2.6 )
add_executable( ${PROJECT_NAME} main.c )
```

`cmake_minimum_required( ... )` is needed in root CMakeLists.txt, always.

The `${PROJECT_NAME}` is variable with value `C`,
which is set by the `project( C )`.

See [c](c).

### 3.2. C++ Example

Simple C++ project.

```cmake
project( CPP )
make_minimum_required( VERSION 2.6 )
file( GLOB SRCS *.c *.cpp *.cc *.h *.hpp )  # a variable called SRCS with all files whose path match "*.c *.cpp..."
add_executable( ${PROJECT_NAME} ${SRCS} )
```

See [cpp](cpp).

### 3.3. C++11 Example

C++11 project.

```cmake
include( CheckCXXCompilerFlag )
check_cxx_compiler_flag( "-std=c++11"   COMPILER_SUPPORTS_CXX11 )
check_cxx_compiler_flag( "-std=c++0x"   COMPILER_SUPPORTS_CXX0X )
if( COMPILER_SUPPORTS_CXX11 )
    if( CMAKE_COMPILER_IS_GNUCXX )
        set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11" )
    else()
        set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11" )
    endif()
elseif( COMPILER_SUPPORTS_CXX0X)
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x" )
else()
    # MSVC, On by default (if available)
endif()
```

See [cpp11](cpp11).

I recommend Visual Studio 2015 Community Edition.

### 3.4. Example to Show How to Modualize Your Project

```cmake
# root cmakelists.txt
project( MODULES )
cmake_minimum_required( VERSION 2.8.3 )

include_directories( ${CMAKE_SOURCE_DIR}/includes )

add_subdirectory( src )
add_subdirectory( demo )

# src dir
add_subdirectory( cubic )
add_subdirectory( extras )
add_subdirectory( square )

# cubic
add_library( LibCubic ${CUBICS} cubic.c )

# demo
project( CALC )
cmake_minimum_required( VERSION 2.6 )

set( EXTRA_LIBS ${EXTRA_LIBS} LibSquare )
set( EXTRA_LIBS ${EXTRA_LIBS} LibExtras )
set( EXTRA_LIBS ${EXTRA_LIBS} LibCubic )

add_executable( Calc calc.c )
target_link_libraries( Calc  ${EXTRA_LIBS} )
```

See [modules](modules).

### 3.5. Example with Support of Boost

```cmake
project( BOOST )
cmake_minimum_required( VERSION 2.6 )

find_package( Boost REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )
LINK_DIRECTORIES( ${Boost_LIBRARY_DIRS} )
set( Boost_USE_STATIC_LIBS        OFF )
set( Boost_USE_MULTITHREADED      ON )
set( Boost_USE_STATIC_RUNTIME     OFF )
set( BOOST_ALL_DYN_LINK           ON ) # force dynamic linking for all libraries

add_executable( ${PROJECT_NAME} main.cpp )
target_link_libraries( ${PROJECT_NAME} ${Boost_LIBRARIES} )
```

Ubuntu install: `sudo apt-get install libboost-all-dev`.

See [boost](boost).

### 3.6. Example with Support of OpenCV

Want to how to configure both opencv 2 & 3 on your system?
Checkout my tutorial: [HOWTO: OpenCV 2 & OpenCV 3 · Issue #4 · district10/cmake-templates](https://github.com/district10/cmake-templates/issues/4).

opencv 2 or less

```cmake
project( OPENCV )
cmake_minimum_required( VERSION 2.6 )

include( $ENV{OpenCV2_DIR}/OpenCVConfig.cmake ) # find_package( OpenCV REQUIRED )

message( STATUS "OpenCV library status:" )
message( STATUS "    version: ${OpenCV_VERSION}" )
message( STATUS "    libraries: ${OpenCV_LIBS}" )
message( STATUS "    include path: ${OpenCV_INCLUDE_DIRS}" )

include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( ${PROJECT_NAME}  minarea.c )
target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS} )
```

opencv 3

```cmake
project( OPENCV3 )
cmake_minimum_required( VERSION 2.8 )

include( $ENV{OpenCV3_DIR}/OpenCVConfig.cmake ) # find_package( OpenCV REQUIRED )

message( STATUS "OpenCV library status:" )
message( STATUS "    version: ${OpenCV_VERSION}" )
message( STATUS "    libraries: ${OpenCV_LIBS}" )
message( STATUS "    include path: ${OpenCV_INCLUDE_DIRS}" )

include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( ${PROJECT_NAME} example.cpp )
target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS} )
```

See

-   [opencv](opencv): for opencv2 or less (VS2010 :smile:, Linux :question:)
-   [opencv3](opencv3): for opencv3 (VS2010 :question:, Linux :smile:)

### 3.7. Example with Support of Qt4

Be sure to make `qmake` caught by CMake, put it in your `$PATH`.

qt4 console

```cmake
find_package( Qt4 REQUIRED )
include( ${QT_USE_FILE} )
set( QT_DONT_USE_QTGUI TRUE )

add_executable( ${PROJECT_NAME} main.cpp )
target_link_libraries( ${PROJECT_NAME}  ${QT_LIBRARIES} )
```

configure file

```cmake
configure_file(
    "${PROJECT_SOURCE_DIR}/Configs.h.in"
    "${PROJECT_BINARY_DIR}/Configs.h" )
```

moc, uic

```cmake
file( GLOB_RECURSE HDRS_FILES *.h *.hpp )
file( GLOB_RECURSE SRCS_FILES *.cpp )
file( GLOB_RECURSE UI_FILES *.ui )

qt4_wrap_cpp( MOC_SRCS ${HDRS_FILES} )
qt4_wrap_ui( UI_HDRS ${UI_FILES} )

source_group( "UI Files" FILES ${UI_FILES} )
source_group( "Generated Files" FILES ${MOC_SRCS} ${UI_HDRS} )

add_library( ${PROJECT_NAME} STATIC ${SRCS_FILES} ${UI_FILES} ${HDRS_FILES} ${MOC_SRCS} ${UI_HDRS} )
target_link_libraries( ${PROJECT_NAME} ${QT_LIBRARIES} )
```

Works like `qmake -project`, one ring to rule them all:

```cmake
project( QT4 )
cmake_minimum_required( VERSION 2.6 )

find_package( Qt4 REQUIRED )
include( ${QT_USE_FILE} )

include_directories( ${CMAKE_SOURCE_DIR}/ )
include_directories( ${CMAKE_BINARY_DIR}/ )

# based on: https://cmake.org/Wiki/CMakeMacroFilterOut
macro( filter_out FILTERS INPUTS OUTPUTS )
    set( FOUT "" )
    foreach( INP ${INPUTS} )
        set( FILTERED 0 )
        foreach( FILT ${FILTERS} )
            if( ${FILTERED} EQUAL 0 )
                if( "${FILT}" STREQUAL "${INP}" )
                    set( FILTERED 1 )
                endif( "${FILT}" STREQUAL "${INP}" )
                if( ${INP} MATCHES ${FILT} )
                    set( FILTERED 1 )
                endif( ${INP} MATCHES ${FILT} )
            endif( ${FILTERED} EQUAL 0 )
        endforeach( FILT ${FILTERS} )
        if( ${FILTERED} EQUAL 0 )
            set( FOUT ${FOUT} ${INP} )
        endif( ${FILTERED} EQUAL 0 )
    endforeach( INP ${INPUTS} )
    set( ${OUTPUTS} ${FOUT} )
endmacro( filter_out FILTERS INPUTS OUTPUTS )

file( GLOB_RECURSE UI_FILES *.ui )
file( GLOB_RECURSE HDRS_FILES *.h *.hpp )
file( GLOB_RECURSE SRCS_FILES *.cpp *.c )
file( GLOB_RECURSE RCS_FILES *.qrc )

set( FILTERS ".*CompilerId.*" )
set( FILTERS ".*CMakeFiles/.*" )
filter_out("${FILTERS}" "${SRCS_FILES}" SRCS_FILES )

qt4_wrap_cpp( MOC_SRCS ${HDRS_FILES} )
qt4_wrap_ui( UI_HDRS ${UI_FILES} )
qt4_add_resources( RCS ${RCS_FILES} )

source_group( "UI Files" FILES ${UI_FILES} )
source_group( "Generated Files" FILES ${MOC_SRCS} ${UI_HDRS} )
source_group( "All Resource Files" FILES ${RCS} )

add_executable( ${PROJECT_NAME}
    ${MOC_SRCS}
    ${HDRS_FILES}
    ${SRCS_FILES}
    ${UI_FILES}
    ${UI_HDRS} ${RCS} )
target_link_libraries( ${PROJECT_NAME} ${QT_LIBRARIES} )
```

See

-   [qt4 console application](qt4-console) (VS2010 :smile:, Linux :smile:)
-   [qt4 GUI application](qt4-gui) (check out the [configs.h.in](qt4-gui/configs.h.in) file) (VS2010 :smile:, Linux :smile:)
-   [qt4 application for lazy people](qt4-project), works like `qmake -project && qmake && make` on Linux (VS2010 :smile:, Linux :smile:)

### 3.8. Example with Support of Qt5

```cmake
project( Qt5Project )
cmake_minimum_required( VERSION 2.8.11 )

#                                           root of your msvc14 x64 prebuild
set( CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "C:/Qt/Qt5-msvc14/5.6/msvc2015_64" )
set( CMAKE_INCLUDE_CURRENT_DIR ON )
set( CMAKE_AUTOMOC ON )

find_package( Qt5Widgets REQUIRED )
qt5_wrap_ui( UI_HEADERS mainwindow.ui )
qt5_add_resources( QRCS resources.qrc )
add_executable( ${PROJECT_NAME} main.cpp mainwindow.cpp ${UI_HEADERS} ${QRCS} )
target_link_libraries( ${PROJECT_NAME} Qt5::Widgets )
```

See [qt5 project](qt5-project).

### 3.9. Get'em Together (advanced examples)

This part is called CMake in Action.

-   [ToyAuthor/luapp: Using lua in C++ style. Build system is CMake.](https://github.com/ToyAuthor/luapp)
    -   a great cmake wrapper for lua, a great c++ wrapper for lua
    -   I forked it, and annotated (in chinese), it's really great! My fork: [4ker/luapp: Using lua in C++ style. Build system is CMake.](https://github.com/4ker/luapp).
-   [district10/algo: 重复造轮子。](https://github.com/district10/algo)
    - Libs
        -   google test (gmock), for testing and benchmarking, etc
        -   cppformat, the missing string formating lib
    -   modulized
    -   advanced linking style
-   <https://github.com/district10/bcp/tree/standalone>

## 4. TODO

-   More documentation
-   More elegant & illustrative examples
-   Planned Examples
    -   for Windows, link `*.lib` files
    -   for Linux, link `*.a`, `*.so` files, set `rpath`
    -   *etc.*

## 5. Snippets & Helper Functions

cpp -> exe

```cmake
file( GLOB SRCS src/*.cpp)
foreach( src ${SRCS} )
    string( REGEX REPLACE "(^.*/|.cpp$)" "" exe ${src} )
    message( STATUS "${exe} <-- ${src}" )
    add_executable( ${exe} ${src} )
endforeach( src )
```

 There are some utility functions in [`utilities.cmake`](utilities.cmake), use `include(utilities.cmake)` to include, then use
 - `print_include_directories()` to print all included directories,
 - `print_all_linked_libraries(your_exe_or_lib)` to print all linked libs,
 - `print_all_variables()` to print all variables

Tip, use `cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=YES ..` to generate compile commands (a json file).

## 6. ReadingList

These links may be useful:

-   [Search · cmake templates](https://github.com/search?utf8=%E2%9C%93&q=cmake+templates)
-   [giddie/qt-cmake-template: Project template using CMake / Qt / NSIS or WiX / MinGW or MSVS combined in easy-to-use form](https://github.com/giddie/qt-cmake-template)
-   [cginternals/cmake-init: Template for reliable, cross-platform C++ project setup using cmake.](https://github.com/cginternals/cmake-init)

## 7. Koan

-   CMake's documentation is not for human. It really smells
-   Adapt to various standards is by no means easy, it's kind of brain fucking
