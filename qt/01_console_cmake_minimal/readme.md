Build in Windows in MSYS2 (UCRT):
```
mkdir build
cd build
cmake -B build ..
cmake --build build
```
or
```
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
mingw32-make
```
