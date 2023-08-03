# A simple example of GTest and GMock usage for free functions in C and static methods in C++

This repository contains quick notes how to build and run GTest and GMock tests for specific use cases.

## Download and Install

- [CMake](https://cmake.org/download/)
- [GTest/Gmock](https://github.com/google/googletest)
```
$ git clone https://github.com/google/googletest.git
$ cd googletest/
$ mkdir build
$ cd build/
$ cmake ..
$ make
$ sudo make install
```

## Build and run Linux (Debian based distros)

```
git clone https://github.com/nemanjadjekic/g_test_mock_free_functions.git
```

### Run C example
```
cd C && bash build_and_run_test.sh

Remove old build folder
Generate cmake files and create build folder
-- The C compiler identification is GNU 11.4.0
-- The CXX compiler identification is GNU 11.4.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found GTest: /usr/local/lib/cmake/GTest/GTestConfig.cmake (found version "1.14.0")  
-- Configuring done
-- Generating done
-- Build files have been written to: /home/nemus/SandBox/g_test_mock_free_functions/C/build
Build tests
[ 50%] Building CXX object CMakeFiles/calculator_test.dir/test/calculator_test.cc.o
[100%] Linking CXX executable calculator_test
[100%] Built target calculator_test
Run tests
[==========] Running 4 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 4 tests from CExampleUnitTest
[ RUN      ] CExampleUnitTest.sum
[       OK ] CExampleUnitTest.sum (0 ms)
[ RUN      ] CExampleUnitTest.subtract
[       OK ] CExampleUnitTest.subtract (0 ms)
[ RUN      ] CExampleUnitTest.multiply
[       OK ] CExampleUnitTest.multiply (0 ms)
[ RUN      ] CExampleUnitTest.divide
[       OK ] CExampleUnitTest.divide (0 ms)
[----------] 4 tests from CExampleUnitTest (0 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 4 tests.
```

### Run CPP example
```
cd CPP && bash build_and_run_test.sh

Remove old build folder
Generate cmake files and create build folder
-- The C compiler identification is GNU 11.4.0
-- The CXX compiler identification is GNU 11.4.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found GTest: /usr/local/lib/cmake/GTest/GTestConfig.cmake (found version "1.14.0")  
-- Configuring done
-- Generating done
-- Build files have been written to: /home/nemus/SandBox/g_test_mock_free_functions/CPP/build
Build tests
[ 50%] Building CXX object CMakeFiles/calculator_test.dir/test/calculator_test.cc.o
[100%] Linking CXX executable calculator_test
[100%] Built target calculator_test
Run tests
[==========] Running 4 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 4 tests from CppExampleUnitTest
[ RUN      ] CppExampleUnitTest.sum
[       OK ] CppExampleUnitTest.sum (0 ms)
[ RUN      ] CppExampleUnitTest.subtract
[       OK ] CppExampleUnitTest.subtract (0 ms)
[ RUN      ] CppExampleUnitTest.multiply
[       OK ] CppExampleUnitTest.multiply (0 ms)
[ RUN      ] CppExampleUnitTest.divide
[       OK ] CppExampleUnitTest.divide (0 ms)
[----------] 4 tests from CppExampleUnitTest (0 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 4 tests.
```

### Note

CMakeLists.txt files are adjusted to machine that allready have GTest and GMock libraries installed. If you would like to fetch googletest library from the cloud please refer [GoogleTest Quickstart:CMake guide](http://google.github.io/googletest/quickstart-cmake.html).


## Reference

Code in this repository is based on the example provided by [Ed-Yang](https://github.com/Ed-Yang) in [gmockc](https://github.com/Ed-Yang/gmockc/tree/master) repository.
