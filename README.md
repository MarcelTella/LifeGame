
# Conway's Game of Life - Project details
This project is the second coursework of the subject Research Computing with C++. Created in 2014-2015, refactored in October 2017

**Author:** Marcel Tella Amo

![ConwaysGameOfLife](https://upload.wikimedia.org/wikipedia/commons/e/e5/Gospers_glider_gun.gif)
![ConwaysGameOfLife](https://upload.wikimedia.org/wikipedia/commons/thumb/e/e0/Game_of_life_glider_gun.svg/610px-Game_of_life_glider_gun.svg.png)

Build Instructions
==================

Tested on Ubuntu 16.04 (gcc).

First of all, clone the repository
```
git clone https://github.com/MarcelTella/LifeGame.git
```

The script utils/compile.sh will compile and run the program as well as the unit testing suite.
```
cd LifeGame/utils
./compile.sh
```
Make sure the paths to the data in ./compile.sh are pointing to the right files.

This will produce an output.txt in the location specified in compile.sh. Then, the output can be easily converted into a video using the MATLAB script utils/videoscript.m
```
nRows = 100;
nCols = 100;
lifeGameOutputFilePath = 'PathToTheOutputFile.txt'
videoscript(lifeGameOutputFilePath, nRows, nCols);
```
