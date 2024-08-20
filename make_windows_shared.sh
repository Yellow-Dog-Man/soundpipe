# Cross-compiles a shared library for windows using mingw

export CXX="x86_64-w64-mingw32-cpp"
export CC="x86_64-w64-mingw32-gcc"
export CPP="x86_64-w64-mingw32-g++"
export LD="x86_64-w64-mingw32-ld"
export AR="x86_64-w64-mingw32-ar"

make libsoundpipe.dll