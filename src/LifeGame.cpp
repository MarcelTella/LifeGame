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
            tmpTable(i, j) = getNewState(Position(i, j));
        }
    }

    _board = tmpTable;
}

int LifeGame::countNeighbours(const Position pos, const state& st) const{
    int count = 0;
    int i = pos.row;
    int j = pos.col;

    if(stateOf(Position(i-1, j)) == st) count++;   //Up
    if(stateOf(Position(i+1, j)) == st) count++;   //Down
    if(stateOf(Position(i, j-1)) == st) count++;   //Left
    if(stateOf(Position(i, j+1)) == st) count++;   //Right
    if(stateOf(Position(i-1, j-1)) == st) count++; //Diagonal top left
    if(stateOf(Position(i-1, j+1)) == st) count++; //Diagonal top right
    if(stateOf(Position(i+1, j+1)) == st) count++; //Diagonal bottom right
    if(stateOf(Position(i+1, j-1)) == st) count++; //Diagonal bottom left

    return count;
}

int LifeGame::countNeighboursAlive(const Position pos) const{
    return countNeighbours(pos, alive);
}

int LifeGame::countNeighboursDead(const Position pos) const{
    return countNeighbours(pos, dead);
}

bool LifeGame::getNewState(const Position pos) const {
    int neighAlive = countNeighboursAlive(pos);
    state thisState = stateOf(pos);

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

state LifeGame::stateOf(const Position pos) const{
    int newI = getIndexWithinBoard(pos.row, rows);
    int newJ = getIndexWithinBoard(pos.col, cols);

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
