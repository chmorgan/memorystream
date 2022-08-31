# MemoryStream

[![Build Status](https://github.com/chmorgan/memorystream/actions/workflows/cmake.yml/badge.svg)](https://github.com/chmorgan/memorystream/actions/workflows/cmake.yml)

A lightweight C implementation of a memory backed stream. Designed for embedded system usage the library
supports standard types and performs founds checking during each call.

## Features
* Allocation free
* Bounds checking
* BSD licensed

Based on MemoryStream from .NET, https://docs.microsoft.com/en-us/dotnet/api/system.io.memorystream


## Building

```
mkdir build
cd build
cmake ../
make
```

## Running tests
Perform the steps above to build

```
make test
```
