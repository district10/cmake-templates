project( QT4_CONSOLE )
cmake_minimum_required( VERSION 2.6 )

find_package( Qt4 REQUIRED )
include( ${QT_USE_FILE} )
set( QT_DONT_USE_QTGUI TRUE )

add_executable( ${PROJECT_NAME} main.cpp )
target_link_libraries( ${PROJECT_NAME}  ${QT_LIBRARIES} )
