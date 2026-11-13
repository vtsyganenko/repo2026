#### CMake
win
```
mkdir build_cmake
cd build_cmake
cmake -G "MinGW Makefiles"
mingw32-make
```
linux (ubuntu 26)
```
mkdir build
cd build
cmake ..
make
```

#### qmake
win
```
mkdir build_qmake
cd build_qmake
qmake-qt5 ..
mingw32-make
```
linux (ubuntu 26)
```
mkdir build
cd build
qmake ..
make
```
