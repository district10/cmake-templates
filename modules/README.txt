This demo shows how to organize code with CMake.

exe    <--- calc.c
calc.c <---depends on---+  includes/*.h  (declarations)
                         \_ static libs  (implementations)
                               \_ LibSquare:     src/square.c
                               |_ LibCubic:      src/cubic.c
                               |_ LibExtras:     src/{power4.c, power5.c}
