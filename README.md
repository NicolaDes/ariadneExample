# ariadneExample
An example of ariadne utilization.

## Dependencies
System dependencies
```
sudo apt install git cmake libboost-system-dev libboost-serialization-dev libboost-thread-dev libgtk2.0-dev libcairo2-dev libbdd-dev
```
```
cd release*
```
```
mkdir build && cd build
```
```
cmake ..
```
```
make
```
```
make test
```
```
sudo make install 
```
```
export LD_LIBRARY_PATH=/usr/local/lib
```

## Compilation

- Create the build directory
```
mkdir build && cd build
```
- Generate makefile files
```
make -j
```
- Binary files are inside `bin` directory

To understand what binaries do, check the relative descriptions inside relative wiki pages.