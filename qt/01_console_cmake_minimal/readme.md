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
Build in Mac (ARM)
```
mkdir build
cd build
cmake -DCMAKE_PREFIX_PATH=/opt/homebrew/opt/qt5 ..
make all
```
Build in Linux (Xubuntu)
```
mkdir build
cd build
cmake ..
make all
```
