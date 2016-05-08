# cmake-templates

Some CMake Templates.

## Conventions

- VS2010 means Windows Visual Studio 2010 project
- Linux means GNU Makefile project
- :smile: means tested okay
- :cry: means test result not sufficiently good
- :question: means not tested yet
- so VS2010 :smile: means the CMakeLists.txt tests good on Visual Studio 2010

## Usage

### Windows

Use `CMake-GUI` to generate Viisual Studio 2010 project, then use Visual Studio to compile & run.

Tutorial: [HOWTO: CMake + Visual Studio 2010 · Issue #1 · district10/cmake-templates](https://github.com/district10/cmake-templates/issues/1).

### Linux

```bash
# cd source dir (there should be a CMakeLists.txt)
mkdir build && cd build
cmake ..
make

# then checkout the generated binary files
```

## C Example

Simple C project. See [c](c). (VS2010 :smile:, Linux :smile:)

## C++ Example

Simple C++ project. See [cpp](cpp). (VS2010 :smile:, Linux :smile:)

## C++11 Example

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
See [cpp11/CMakeLists.txt](cpp11/CMakeLists.txt) for further infomation.

Bonus: A VS2010 example with some C++11 features: [cpp11_vs2010](cpp11_vs2010).

## Example to Show How to Modualize Your Project

See [modules](modules). (VS2010 :smile:, Linux :smile:)

## Example with Support of Boost

See [boost](boost). (VS2010 :smile:, Linux :smile:)

## Example with Support of OpenCV

See

  - [opencv](opencv): for opencv2 or less (VS2010 :smile:, Linux :question:)
  - [opencv3](opencv3): for opencv3 (temporarily not available) (VS2010 :question:, Linux :smile:)

(I have OpenCV2 on Win, and OpenCV3 on Linux, that's why...)

## Example with Support of Qt4

See

  - [qt4 console application](qt4-console) (VS2010 :smile:, Linux :smile:)
  - [qt4 GUI application](qt4-gui) (check out the [configs.h.in](qt4-gui/configs.h.in) file) (VS2010 :smile:, Linux :smile:)
  - [qt4 application for lazy people](qt4-project), works like `qmake -project && qmake && make` on Linux (VS2010 :smile:, Linux :smile:)

## Example with Support of Qt5

TODO

## TODO

-   More documentation
-   More elegant & illustrative examples
-   Planned Examples
    + for Windows, link `*.lib` files
    + for Linux, link `*.a`, `*.so` files, set `rpath`
    + *etc.*

## ReadingList

These links may be useful:

  - [Search · cmake templates](https://github.com/search?utf8=%E2%9C%93&q=cmake+templates)
  - [giddie/qt-cmake-template: Project template using CMake / Qt / NSIS or WiX / MinGW or MSVS combined in easy-to-use form](https://github.com/giddie/qt-cmake-template)
  - [cginternals/cmake-init: Template for reliable, cross-platform C++ project setup using cmake.](https://github.com/cginternals/cmake-init)
  - [district10/algo: 重复造轮子。](https://github.com/district10/algo)

## Koan

-   CMake's documentation is not for human. It really smells
-   Adapt to different standards is by no means easy
