project( OPENCV )
cmake_minimum_required( VERSION 2.6 )

find_package( OpenCV REQUIRED )
# include( $ENV{OpenCV2_DIR}/OpenCVConfig.cmake )

add_executable( ${PROJECT_NAME}  minarea.c )
target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS} )
