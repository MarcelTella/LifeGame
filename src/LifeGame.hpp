#ifndef LIFEGAME_H
#define LIFEGAME_H

#include <iostream>
#include <Eigen/Dense>
#include "general.hpp"
#include "BoardFileManager.hpp"

using namespace std;

class LifeGame
{
	private:
        Board _board;
        int _nRows;
        int _nCols;

        int getIndexWithinBoard(const int, const dimension&) const;
        int countNeighbours(const int, const int, const state&) const;
        bool aliveAndTwoOrThreeNeighboursAlive(const state&, const int neighAlive) const;
        bool deadButThreeNeighboursAlive(const state&, const int neighAlive) const;
	public:
		LifeGame();
        LifeGame(string path);

        void updateBoard();
        bool getNewState(const int i, const int j) const;
        int countNeighboursAlive(const int, const int) const;
        int countNeighboursDead(const int, const int) const;
        state stateOf(const int i, const int j) const;
        void writeInFile(const string outputPath) const;
        friend ostream& operator<< (ostream&, const LifeGame&);
};

#endif
