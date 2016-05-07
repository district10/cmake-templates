project( QT5 )
cmake_minimum_required( VERSION 2.8.11 )

set( CMAKE_INCLUDE_CURRENT_DIR ON )
set( CMAKE_AUTOMOC ON ) # Instruct CMake to run moc automatically when needed.

# Find the QtWidgets library
find_package( Qt5Widgets )

file( GLOB_RECURSE UI_FILES *.ui)
file (GLOB_RECURSE SRCS_FILES *.cpp )

# Tell CMake to create the helloworld executable
add_executable( ${PROJECT_NAME} main.cpp )

# Use the Widgets module from Qt 5.
target_link_libraries( ${PROJECT_NAME} Qt5::Widgets )
