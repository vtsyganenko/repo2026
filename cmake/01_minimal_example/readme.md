Linux install
```
sudo apt update
sudo apt install cmake
cmake --version
sudo apt install build-essential
```
Linux / MacOS build
```
mkdir build
cd build
cmake ..
make all
```

Windows - use MSYS2
1. Install MSYS2 from msys2.org
2. Update PATH with:
```
C:\msys64\ucrt64\bin
```
3. Work in the UCRT64 environment:

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
```
This commands use ninja.

Alternative with Makefile:
```
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
mingw32-make
```
