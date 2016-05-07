# cmake-templates

Some CMake Templates.

## Convensions

- VS2010 means Windows Visual Studio 2010 project
- Linux means GNU Makefile project
- `<Good>` means tested okay
- `<Bad>` means test result not sufficiently good
- `<?>` means not tested yet

## Usage

### Windows

Use `CMake-GUI` to generate Viisual Studio 2010 project, then use Visual Studio to compile & run.

### Linux

```bash
# cd source dir (there should be a CMakeLists.txt)
mkdir build && cd build
cmake ..
make

# then checkout the generated binary files
```

## C Example

Simple C project. See [c](c). (VS2010 `<Good>`, Linux `<Good>`)

## C++ Example

Simple C++ project. See [cpp](cpp). (VS2010 `<Good>`, Linux `<Good>`)

## C++11 Example

C++ project. See [cpp](cpp). (VS2010 `<?>`, Linux `<Good>`)

Only tested a few C++11 (aka C++0x) features:

  - auto
  - const iterator
  - foreach
  - lambda function

## Example to Show How to Modualize Your Project

See [modules](modules). (VS2010 `<Good>`, Linux `<Good>`)

## Example with Support of BOOST

See [boost](boost). (VS2010 `<Good>`, Linux `<Good>`)

## Example with Support of OpenCV

See

  - [opencv](opencv): for opencv2 or less (VS2010 `<Good>`, Linux `<?>`)
  - [opencv3](opencv3): for opencv3 (temporarily not available) (VS2010 `<?>`, Linux `<Good>`)

## Example with Support of Qt4

See

  - [qt4 console application](qt4-console) (VS2010 `<Good>`, Linux `<Good>`)
  - [qt4 GUI application](qt4-gui) (check out the [configs.h.in](qt4-gui/configs.h.in) file) (VS2010 `<Good>`, Linux `<Good>`)
  - [qt4 application for lazy people](qt4-project), works like `qmake -project && qmake && make` on Linux (VS2010 `<Good>`, Linux `<Good>`)

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

CMake's documentation is not for human, really terrible.
