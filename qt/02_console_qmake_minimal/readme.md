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
