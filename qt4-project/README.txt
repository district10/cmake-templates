Suppose you've got these files:

    .
    |-  basicdrawing.qrc
    |-  images/
    |      |-  qt-logo.png
            -  brick.png
    |-  renderarea.cpp
    |-  renderarea.h
    |-  window.cpp
    |-  window.h

You can run `qmake -project` to generate a *.pro file, 
then use qtcreator to open this project.

Or use this CMakeLists.txt to build a Makefile or Visual Studio project.
Especially good for these lazy people.

--------------------------------
(Code copied from Qt4 examples.)
