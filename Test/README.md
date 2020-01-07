```
git clone googletest
```

## Execute

one line code (コピペしやすいだけ)

```
>
mkdir build && cd build
>
cd .. && rmdir /s /Q build && mkdir build && cd build && cmake -G "Visual Studio 16 2019" -D CMAKE_CXX_COMPILER="C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Tools/MSVC/14.24.28314/bin/Hostx86/x86/cl.exe" .. && cmake --build . && Debug\main.exe
> ctest --build-config Debug
```

```
cd .. && rmdir /s /Q build && mkdir build && cd build && cmake -G "Visual Studio 16 2019" -D CMAKE_CXX_COMPILER="C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Tools/MSVC/14.24.28314/bin/Hostx86/x86/cl.exe" .. && cmake --build . && ctest --build-config Debug
```