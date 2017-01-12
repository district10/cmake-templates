Mods of OpenCV official example cmake demo:

    <https://github.com/Itseez/opencv/tree/2.4/samples/c/example_cmake>

See cpp version at:

    + <https://github.com/Itseez/opencv/tree/master/samples/cpp/example_cmake>

Environment var: $OpenCV_DIR

    in this path, it should contain `OpenCVConfig.cmake'.

Build & Run:

    mkdir build && cd build
    export OpenCV2_DIR=/home/tzx/Downloads/archive/opencv-2.4.13/build
    cmake ..
    make
    ./OPENCV
