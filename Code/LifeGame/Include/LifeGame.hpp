#ifndef __LIFEGAME_H__
#define __LIFEGAME_H__

#include <iostream>
#include <Eigen/Dense>


using namespace std;

enum state{dead, alive};

class LifeGame
{
	Eigen::Matrix<bool, Eigen::Dynamic, Eigen::Dynamic> board;
	int NumRows;
	int NumCols;

	public:
	LifeGame();
	LifeGame(string input_path);
	void loadFile(string input_path);
	void updateBoard();
	bool getNewState(int i, int j) const;
	int countNeighbours(int i,int j,state st) const;
	bool stateOf(int i,int j) const;
	void writeInFile(string output_path);

	friend ostream& operator<< (ostream& os, const LifeGame& lg);
};


#endif
