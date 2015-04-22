#ifndef __LIFEGAME_H__
#define __LIFEGAME_H__

#include <iostream>
#include <Eigen/Dense>

using namespace std;

enum state{dead, alive};

template<typename T>
class LifeGame
{
	Eigen::Matrix<bool, Eigen::Dynamic, Eigen::Dynamic> board;
	int NumRows;
	int NumCols;

	public:
	LifeGame<T>();
	LifeGame<T>(string input_path);
	void loadFile(string input_path);
	void updateBoard();
	bool getNewState(int i, int j) const;
	int countNeighbours(int i,int j,state st) const;
	bool stateOf(int i,int j) const;
	void writeInFile(string output_path);

	template<typename T1>
	friend ostream& operator<< (ostream& os, const LifeGame<T1>& lg);
};

#include "../LifeGame.cc"
#endif
