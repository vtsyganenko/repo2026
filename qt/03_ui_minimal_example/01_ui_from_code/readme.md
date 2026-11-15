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
MacOS
```
mkdir build
cd build
cmake -DCMAKE_PREFIX_PATH=/opt/homebrew/opt/qt5 ..
make all
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
MacOS
```
mkdir build
cd build
qmake ..
make all
```
