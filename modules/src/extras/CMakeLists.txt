file (GLOB EXTRAS *.c)
add_library( LibExtras ${EXTRAS} )
target_link_libraries( LibExtras LibSquare LibCubic )
