project( MODULES )
cmake_minimum_required( VERSION 2.8.3 )

include_directories( ${CMAKE_SOURCE_DIR}/includes )

add_subdirectory( src )
add_subdirectory( demo )
