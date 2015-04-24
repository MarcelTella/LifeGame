# Project details
This project is the second coursework of the subject Research Computing with C++

# Author
Marcel Tella Amo
research-computing-with-cpp-demo
================================

Build Instructions
==================

Tested on Linux (gcc).

First of all, clone the repository
```
git clone https://github.com/MarcelTella/LifeGame.git
```

The script Utils/Compile.sh followed by Utils/un.sh will execute the program.
```
cd Utils
./Compile.sh
./run.sh
```
==================
Alternatively, the code can be compiled and run by using
```
mkdir research-computing-with-cpp-demo-build
cd research-computing-with-cpp-demo-build
ccmake ../research-computing-with-cpp-demo
make

```
And an example of execution would be
```
cd RCCPP-build/bin
export OMP_NUM_THREADS=8;time ./LifeGame --in ../../../Data/init4000.txt --out b.txt --iter 50
```
