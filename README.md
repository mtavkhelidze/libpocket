# libpocket — Test-Drive Implementation of Data Structures & Algorithms in C++

## Description

`libpocket` is test-driven implementation of stuff found in Lee Wittenberg's [Data
Structures and Algorithms in C++: Pocket Primer](1) (hence the name) — an
exercise aimed at refreshing C++, CMake, TDD, and, well, data structures and
algorithms.

_**Safety warning**: do not use this in production unless you really have to._

## Build

### Debug and Test

```bash
$ mkdir -p build
$ cd build
$ cmake -DCMAKE_BUILD_TYPE=Debug ../
$ cmake --build .
$ ctest
```

To see Google Tests' verbose output, do
```bash
$ ctest -V
```

## Release

```bash
$ mkdir -p build
$ cd build
$ cmake -DCMAKE_BUILD_TYPE=Release ../
$ cmake --build .
```

## Install

```bash
$ cd build
$ cmake --build . --clean-first --target install
```


[1]: https://www.amazon.com/Data-Structures-Algorithms-Pocket-Primer/dp/1683920848
