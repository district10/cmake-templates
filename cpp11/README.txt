Tested C++ feauture:

  - auto
  - const iterator
  - lambda calculas
  - new for loop (foreach)

In Visual Studio 2010, you can use:

  - auto
  - const iterator
  - lambda calculas

without any setup, see CMakeLists.txt for further information.

-------------------------------------------------------------

C++11 support can't be covered in a simple and elegant CMakeLists.txt,
you I won't continue test C++11 features here further. These links may
be useful:

  - <http://stackoverflow.com/questions/10851247/how-to-activate-c-11-in-cmake>
  - <http://stackoverflow.com/questions/10984442/how-to-detect-c11-support-of-a-compiler-with-cmake/20165220>

My advice is:

  - don't use `for( int i, v )' feature
  - be conservative, use lambda, const iterator, auto is pretty much enough
  - for VS2010 project, check
    <https://github.com/district10/cmake-templates/tree/master/cpp11_vs2010>
  - for Linux GNUMake, this CMakeList.txt works fine    
