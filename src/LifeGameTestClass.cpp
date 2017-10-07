#include <iostream>
#include "LifeGameTestClass.hpp"

using namespace std;

LifeGameTestClass::LifeGameTestClass(const Board& b){
    _board = b;
}

Board LifeGameTestClass::getBoard(){
    return _board;
}
