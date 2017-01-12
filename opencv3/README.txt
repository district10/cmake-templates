Copied from: https://github.com/Itseez/opencv/tree/master/samples/cpp/example_cmake

How to configure OpenCV 3?

-   Windows

    +   Visual Studio 2015

            1.  goto <http://sourceforge.net/projects/opencvlibrary/files/opencv-win/3.1.0/opencv-3.1.0.exe/download>,
                download prebuild for Windows;

            2.  set environment variable: $OpenCV_DIR to `<prebuild_root_dir>\build',
                there should contain a file called `OpenCVConfig.cmake`;

            3.  add `%OpenCV_DIR%\x64\vc14\bin' to your $PATH.

Build & Run:

    mkdir build && cd build
    export OpenCV3_DIR=/usr/local/share/OpenCV
    cmake ..
    make
    ./OPENCV3
