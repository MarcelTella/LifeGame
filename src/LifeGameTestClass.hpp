#ifndef LIFEGAME_TESTCLASS_H
#define LIFEGAME_TESTCLASS_H

#include <iostream>
#include <Eigen/Dense>
#include "general.hpp"
#include <string>
#include "LifeGame.hpp"

using namespace std;

class LifeGameTestClass : public LifeGame
{
    public:
        LifeGameTestClass(const Board&);
        LifeGameTestClass(const string str) : LifeGame(str){};
        Board getBoard();
};

#endif
