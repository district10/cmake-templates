# cmake-templates

Some CMake Templates.

## 1. Overview

**Conventions**

- :smile: means tested okay/good
- :cry: means test result not sufficiently good
- :question: means not tested yet

| Project                       | Linux + GCC 4.8+ | Win + VS2010 | Win + VS2015 |
| :---------------------------: | :--------------: | :----------: | :----------: |
| [c][refc]                     | :smile:          |  :smile:     | :smile:      |
| [c++][refcpp]                 | :smile:          |  :smile:     | :smile:      |
| [c++11][refcpp11]             | :smile:          |  :bad:       | :smile:      |
| [c++11vs2010][refcpp11vs2010] | :smile:          |  :smile:     | :smile:      |
| [module][refmodule]           | :smile:          |  :smile:     | :smile:      |
| [opencv][refocv]              | :question:       |  :smile:     | :question:   |
| [opencv3][refocv3]            | :smile:          |  :question:  | :smile:      |
| [boost][refboost]             | :smile:          |  :smile:     | :question:   |
| [qt4-console][refqt4c]        | :smile:          |  :smile:     | :smile:      |
| [qt4-gui][refqt4g]            | :smile:          |  :smile:     | :smile:      |
| [qt4-project][refqt4p]        | :smile:          |  :smile:     | :smile:      |
| [qt5-project][refqt5p]        | :question:       |  :question:  | :smile:      |

[refc]: #31c-example
[refcpp]: #32c-example
[refcpp11]: #33c11-example
[refcpp11vs2010]: #33c11-example
[refmodule]: #34example-to-show-how-to-modualize-your-project
[refocv]: #35example-with-support-of-opencv
[refocv3]: #35example-with-support-of-opencv
[refboost]: #36example-with-support-of-boost
[refqt4c]: #37example-with-support-of-qt4
[refqt4g]: #37example-with-support-of-qt4
[refqt4p]: #37example-with-support-of-qt4
[refqt5p]: #38example-with-support-of-qt5

## 2. Usage

### 2.1. Windows

Use `CMake-GUI` to generate Visual Studio 2010 project, then use Visual Studio to compile & run.

Tutorial: [HOWTO: Win + CMake + Visual Studio 2010 · Issue #1 · district10/cmake-templates](https://github.com/district10/cmake-templates/issues/1).

### 2.2. Linux

```bash
# cd source dir (there should be a CMakeLists.txt)
mkdir build && cd build
cmake ..
make

# then checkout the generated binary files
```

## 3. Examples

### 3.1. C Example

Simple C project. See [c](c). (VS2010 :smile:, Linux :smile:)

### 3.2. C++ Example

Simple C++ project. See [cpp](cpp). (VS2010 :smile:, Linux :smile:)

### 3.3. C++11 Example

C++ project. See [cpp11](cpp11). (VS2010 :cry: :question:, Linux :smile:)

C++11 (aka C++0x) features works on Linux:

  - auto
  - const iterator
  - foreach (I mean `for(type varname, container)`.)
  - lambda function

On VS2010:

  - auto
  - const iterator
  - lambda function

VS2010 by default supports 1) auto; 2) const iterator; 3) lambda, but not foreach.
See [cpp11/CMakeLists.txt](cpp11/CMakeLists.txt) for further information.

Bonus: A VS2010 example with some C++11 features: [cpp11_vs2010](cpp11_vs2010).

### 3.4. Example to Show How to Modualize Your Project

See [modules](modules). (VS2010 :smile:, Linux :smile:)

### 3.5. Example with Support of Boost

See [boost](boost). (VS2010 :smile:, Linux :smile:)

### 3.6. Example with Support of OpenCV

See

  - [opencv](opencv): for opencv2 or less (VS2010 :smile:, Linux :question:)
  - [opencv3](opencv3): for opencv3 (VS2010 :question:, Linux :smile:)

(I have OpenCV2 on Win, and OpenCV3 on Linux, that's why...)

### 3.7. Example with Support of Qt4

See

  - [qt4 console application](qt4-console) (VS2010 :smile:, Linux :smile:)
  - [qt4 GUI application](qt4-gui) (check out the [configs.h.in](qt4-gui/configs.h.in) file) (VS2010 :smile:, Linux :smile:)
  - [qt4 application for lazy people](qt4-project), works like `qmake -project && qmake && make` on Linux (VS2010 :smile:, Linux :smile:)

### 3.8. Example with Support of Qt5

TODO

### 3.9. Get'em Together (advanced examples)

This part is called CMake in Action.

-   [ToyAuthor/luapp: Using lua in C++ style. Build system is CMake.](https://github.com/ToyAuthor/luapp)

    +   a great cmake wrapper for lua, a great c++ wrapper for lua
    +   I forked it, and annotated (in chinese), it's really great! My fork: [4ker/luapp: Using lua in C++ style. Build system is CMake.](https://github.com/4ker/luapp).

-   [district10/algo: 重复造轮子。](https://github.com/district10/algo)

    + Libs
        * google test (gmock), for testing and benchmarking, etc
        * cppformat, the missing string formating lib
    + modulized
    + advanced linking style

-   TODO...

## 4. TODO

-   More documentation
-   More elegant & illustrative examples
-   Planned Examples
    + for Windows, link `*.lib` files
    + for Linux, link `*.a`, `*.so` files, set `rpath`
    + *etc.*

## 5. ReadingList

These links may be useful:

  - [Search · cmake templates](https://github.com/search?utf8=%E2%9C%93&q=cmake+templates)
  - [giddie/qt-cmake-template: Project template using CMake / Qt / NSIS or WiX / MinGW or MSVS combined in easy-to-use form](https://github.com/giddie/qt-cmake-template)
  - [cginternals/cmake-init: Template for reliable, cross-platform C++ project setup using cmake.](https://github.com/cginternals/cmake-init)

## 6. Koan

-   CMake's documentation is not for human. It really smells
-   Adapt to various standards is by no means easy, it's kind of brain fucking
