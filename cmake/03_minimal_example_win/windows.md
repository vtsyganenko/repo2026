Use MSYS2:

1. Install MSYS2 from msys2.org
2. Update PATH with:
```
C:\msys64\ucrt64\bin
```
3. Work in UCRT64 environment. 

Install gcc:
```
pacman -S mingw-w64-ucrt-x86_64-gcc
```
Check with 
```
g++ --version
```
Install make:
```
pacman -S mingw-w64-ucrt-x86_64-make
```

Install cmake:
```
pacman -S mingw-w64-ucrt-x86_64-cmake
```
Check with:
```
cmake --version
```

After this, we can build minimal example with:
```
mkdir build
cd build
cmake ..
cmake --build .
./test_win.exe
```
