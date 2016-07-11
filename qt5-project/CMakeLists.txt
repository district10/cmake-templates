project( Qt5Project )
cmake_minimum_required( VERSION 2.8.11 )

# root of your msvc14 x64 prebuild, there should be a `/lib/cmake` dir
set( CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} $ENV{QT5_DIR} )
set( CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "C:/Qt/VS2015x64/Qt5.6.0/5.6/msvc2015_64" ) # remember to add `C:\Qt\VS2015x64\Qt5.6.0\5.6\msvc2015_64\bin` to %PATH%
set( CMAKE_INCLUDE_CURRENT_DIR ON )
set( CMAKE_AUTOMOC ON )

find_package( Qt5Widgets REQUIRED )
qt5_wrap_ui( UI_HEADERS mainwindow.ui )
qt5_add_resources( QRCS resources.qrc )
add_executable( ${PROJECT_NAME} main.cpp mainwindow.cpp ${UI_HEADERS} ${QRCS} )
target_link_libraries( ${PROJECT_NAME} Qt5::Widgets )
