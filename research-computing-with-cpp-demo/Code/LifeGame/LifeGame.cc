#include <iostream>
#include <fstream>
#include "LifeGame.hpp"

using namespace std;

template<typename T>
LifeGame<T>::LifeGame()
{
	int defaultValue = 10;
	NumRows = defaultValue;
	NumCols = defaultValue;
	board.resize(NumRows, NumCols);
}

template<typename T>
LifeGame<T>::LifeGame(string input_path)
{
	loadFile(input_path);
}

template<typename T>
void LifeGame<T>::loadFile(string path)
{
	//Open the file
	ifstream file(path.c_str());

	//Making sure that I can read.
	if(!file.is_open()) throw exception();

	string line;
	//Read the cols
	getline(file, line);

	//Making sure not empty
	if (line.size() == 0) throw exception();

	//Assign the cols
	NumRows = atoi(line.c_str());

	//Read the rows
	getline(file, line);

	//Assign the rows
	NumCols = atoi(line.c_str());

	//Create the matrix
	board.resize(NumRows, NumCols);

	for(int ii=0; ii<NumRows ; ii++){
		try{
			getline(file, line);
		}catch(exception &e){
			cout << e.what() << endl;
		}

		//filling the object
		istringstream iss(line);
		T temp;
		for(int i=0; i<NumCols ; i++){
			iss >> temp;
			board(ii, i) = (temp == 1);
		}

	}
}

template<typename T>
void LifeGame<T>::writeInFile(string output_path)
{
	  ofstream myfile;
	  myfile.open(output_path.c_str(), std::ios_base::app);
	  myfile << board << endl << endl;
	  myfile.close();
}

template<typename T>
void LifeGame<T>::updateBoard()
{
	Eigen::Matrix <T,Eigen::Dynamic,Eigen::Dynamic> tmpTable(NumRows, NumCols);

	for(int i=0; i<tmpTable.rows(); i++){
		for (int j=0; j<tmpTable.cols(); j++){
			tmpTable(i,j) = getNewState(i, j);
		}
	}

	board = tmpTable;
}

template<typename T>
int LifeGame<T>::countNeighbours(int i, int j, state st) const
{
	int count = 0;
	//8 cases
	//Up
	if( stateOf(i-1,j) == st){
		count++;
	}
	//Down
	if( stateOf(i+1,j) == st){
		count++;
	}
	//Left
	if( stateOf(i,j-1) == st){
		count++;
	}
	//Right
	if( stateOf(i,j+1) == st){
		count++;
	}
	//Diagonal top left
	if( stateOf(i-1,j-1) == st){
		count++;
	}
	//Diagonal top right
	if( stateOf(i-1,j+1) == st){
		count++;
	}
	//Diagonal bottom right
	if( stateOf(i+1,j+1) == st){
		count++;
	}
	//Diagonal bottom left
	if( stateOf(i+1,j-1) == st){
		count++;
	}
	return count;
}

template<typename T>
bool LifeGame<T>::getNewState(int i, int j) const
{

	int dNeigh = countNeighbours(i, j, dead);
	int aNeigh = countNeighbours(i, j, alive);

	//First rule

	if (aNeigh == 3 && stateOf(i,j) == dead){
		return alive;
	}
	else if(stateOf(i,j) == alive && (aNeigh == 2 || aNeigh == 3) ){
		return alive;
	}

	return dead;
}

template<typename T>
bool LifeGame<T>::stateOf(int i, int j) const
{
	int newI, newJ;
	if(i<0){
		newI = NumRows+i;
	}
	else{
		newI = i%NumRows;
	}

	if(j<0){
		newJ = NumCols+j;
	}
	else{
		newJ = j%NumCols;
	}

	return board(newI,newJ);
}

template<typename T>
ostream& operator<<(ostream& os, const LifeGame<T>& lg)
{
	cout << lg.board << endl;
    return os;
}
