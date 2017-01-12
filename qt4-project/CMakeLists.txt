project( QT4 )
cmake_minimum_required( VERSION 2.6 )

find_package( Qt4 REQUIRED )
include( ${QT_USE_FILE} )

include_directories( ${CMAKE_SOURCE_DIR}/ )
include_directories( ${CMAKE_BINARY_DIR}/ )

# based on: https://cmake.org/Wiki/CMakeMacroFilterOut
macro( filter_out FILTERS INPUTS OUTPUTS )
    set( FOUT "" )
    foreach( INP ${INPUTS} )
        set( FILTERED 0 )
        foreach( FILT ${FILTERS} )
            if( ${FILTERED} EQUAL 0 )
                if( "${FILT}" STREQUAL "${INP}" )
                    set( FILTERED 1 )
                endif( "${FILT}" STREQUAL "${INP}" )
                if( ${INP} MATCHES ${FILT} )
                    set( FILTERED 1 )
                endif( ${INP} MATCHES ${FILT} )
            endif( ${FILTERED} EQUAL 0 )
        endforeach( FILT ${FILTERS} )
        if( ${FILTERED} EQUAL 0 )
            set( FOUT ${FOUT} ${INP} )
        endif( ${FILTERED} EQUAL 0 )
    endforeach( INP ${INPUTS} )
    set( ${OUTPUTS} ${FOUT} )
endmacro( filter_out FILTERS INPUTS OUTPUTS )

file( GLOB_RECURSE UI_FILES *.ui )
file( GLOB_RECURSE HDRS_FILES *.h *.hpp )
file( GLOB_RECURSE SRCS_FILES *.cpp *.c )
file( GLOB_RECURSE RCS_FILES *.qrc )

set( FILTERS ".*CompilerId.*" )
set( FILTERS ".*CMakeFiles/.*" )
filter_out("${FILTERS}" "${SRCS_FILES}" SRCS_FILES )

qt4_wrap_cpp( MOC_SRCS ${HDRS_FILES} )
qt4_wrap_ui( UI_HDRS ${UI_FILES} )
qt4_add_resources( RCS ${RCS_FILES} )

source_group( "UI Files" FILES ${UI_FILES} )
source_group( "Generated Files" FILES ${MOC_SRCS} ${UI_HDRS} )
source_group( "All Resource Files" FILES ${RCS} )

add_executable( ${PROJECT_NAME}
    ${MOC_SRCS}
    ${HDRS_FILES}
    ${SRCS_FILES}
    ${UI_FILES}
    ${UI_HDRS} ${RCS} )
target_link_libraries( ${PROJECT_NAME} ${QT_LIBRARIES} )
