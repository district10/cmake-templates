project( CALC )
cmake_minimum_required( VERSION 2.6 )

set( EXTRA_LIBS ${EXTRA_LIBS} LibSquare )
set( EXTRA_LIBS ${EXTRA_LIBS} LibExtras )
set( EXTRA_LIBS ${EXTRA_LIBS} LibCubic )

add_executable( Calc calc.c )
target_link_libraries( Calc  ${EXTRA_LIBS} )
