#include <iostream>
#include "LifeGame.hpp"
#include "BoardFileManager.hpp"

using namespace std;

LifeGame::LifeGame(){
    int defaultValue = 10;
    _board.resize(defaultValue, defaultValue);
}

LifeGame::LifeGame(string inputPath){
    BoardFileManager::loadFile(inputPath, _board);
}

void LifeGame::updateBoard(){
    Board tmpTable(getRows(), getCols());

    for(int i=0; i<tmpTable.rows(); i++){
        for (int j=0; j < tmpTable.cols(); j++){
            tmpTable(i, j) = getNewState(i, j);
        }
    }

    _board = tmpTable;
}

int LifeGame::countNeighbours(const int i, const int j, const state& st) const{
    int count = 0;

    if(stateOf(i-1, j) == st) count++;   //Up
    if(stateOf(i+1, j) == st) count++;   //Down
    if(stateOf(i, j-1) == st) count++;   //Left
    if(stateOf(i, j+1) == st) count++;   //Right
    if(stateOf(i-1, j-1) == st) count++; //Diagonal top left
    if(stateOf(i-1, j+1) == st) count++; //Diagonal top right
    if(stateOf(i+1, j+1) == st) count++; //Diagonal bottom right
    if(stateOf(i+1, j-1) == st) count++; //Diagonal bottom left

    return count;
}

int LifeGame::countNeighboursAlive(const int i, const int j) const{
    return countNeighbours(i, j, alive);
}

int LifeGame::countNeighboursDead(const int i, const int j) const{
    return countNeighbours(i, j, dead);
}

bool LifeGame::getNewState(int i, int j) const {
    int neighAlive = countNeighboursAlive(i, j);
    state thisState = stateOf(i, j);

    if (deadButThreeNeighboursAlive(thisState, neighAlive) ||
            aliveAndTwoOrThreeNeighboursAlive(thisState, neighAlive)){
        return alive;
    }

    return dead;
}

bool LifeGame::deadButThreeNeighboursAlive(const state& st, const int neighboursAlive) const{
    return (neighboursAlive == 3) && (st == dead);
}

bool LifeGame::aliveAndTwoOrThreeNeighboursAlive(const state& st, const int neighboursAlive) const{
    return (st == alive) && (neighboursAlive == 2 || neighboursAlive == 3);
}

state LifeGame::stateOf(const int i, const int j) const{
    int newI = getIndexWithinBoard(i, rows);
    int newJ = getIndexWithinBoard(j, cols);

    if (_board(newI, newJ)) return alive;
    else return dead;
}

int LifeGame::getIndexWithinBoard(const int index, const dimension& d) const{
    int nCells;
    if (d == cols)
        nCells = getCols();
    else
        nCells = getRows();

    if(index < 0)
        return (nCells - (abs(index) % nCells)) % nCells;
    else
        return index % nCells;
}

void LifeGame::writeInFile(const string outputPath) const{
    BoardFileManager::writeInFile(outputPath, _board);
}

ostream& operator << (ostream& os, const LifeGame& lg){
    cout << lg._board << endl;
    return os;
}

int LifeGame::getCols() const{
    return _board.cols();
}

int LifeGame::getRows() const{
    return _board.rows();
}
