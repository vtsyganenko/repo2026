Build in Windows in MSYS2 (UCRT):
```
mkdir build
cd build
qmake-qt5 ..
mingw32-make
```
or we can set debug:
```
qmake-qt5 .. CONFIG+=debug
```
Build in Mac (ARM)
```
mkdir build
cd build
qmake ..
make all
```
Build in Linux (Xubuntu)
```
mkdir build
cd build
qmake ..
make all
```
