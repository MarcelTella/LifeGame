#include <iostream>
#include <fstream>
#include <omp.h>
#include <GeneralException.hpp>
#include <IncorrectInitialStateException.hpp>
#include <IncorrectSizesException.hpp>
#include <NoFileFoundException.hpp>
#include <LifeGame.hpp>

using namespace std;

LifeGame::LifeGame()
{
	int defaultValue = 10;
	NumRows = defaultValue;
	NumCols = defaultValue;
	board.resize(NumRows, NumCols);
}

LifeGame::LifeGame(string input_path)
{
	loadFile(input_path);
}

void LifeGame::loadFile(string path)
{
	//Open the file
	ifstream file(path.c_str());

	//Making sure that I can read.
	if(!file.is_open()) throw NoFileFoundException("No File Found");

	string line;
	//Read the cols
	getline(file, line);

	//Assign the cols
	NumRows = atoi(line.c_str());


	if (line.size() == 0) throw IncorrectSizesException("Incorrect Sizes");
	getline(file, line);

	//Assign the rows
	NumCols = atoi(line.c_str());

	//Create the matrix
	board.resize(NumRows, NumCols);

	int rows = 0;
	bool read;

	for(int ii=0; ii<NumRows ; ii++){
			
		getline(file, line);
		if (line.size() == 0) throw IncorrectInitialStateException("Wrong Initial State - No data");

		//filling the object
		istringstream iss(line);
		string temp;
		int iTemp;
		int columns = 0;
		for(int i=0; i<NumCols ; i++){

			read = (iss >> temp);
			if (!read) throw IncorrectInitialStateException("Wrong Initial State - Not enough data");

			iTemp = atoi(temp.c_str());
			if (iTemp != 1 && iTemp != 0) throw IncorrectInitialStateException("Wrong Initial State - Value not allowed");
			board(ii, i) = (iTemp == 1);
			columns++;
		}
		if (columns != NumCols)throw IncorrectInitialStateException("Wrong Initial State - Error in the number of cols.");
		rows++;
	}
	if (rows != NumRows)throw IncorrectInitialStateException("Wrong Initial State - Error in the number of rows");
}


void LifeGame::writeInFile(string output_path)
{
	  ofstream myfile;
	  myfile.open(output_path.c_str(), std::ios_base::app);
	  myfile << board << endl << endl;
	  myfile.close();
}

void LifeGame::updateBoard()
{
	Eigen::Matrix <bool,Eigen::Dynamic,Eigen::Dynamic> tmpTable(NumRows, NumCols);

	omp_set_dynamic(1);
	#pragma omp parallel private(tmpTable)// for //
	{
		//int nthreads, procs, maxt, inpar, dynamic, nested;

		// Get environment information
		/*procs = omp_get_num_procs();
		nthreads = omp_get_num_threads();
		maxt = omp_get_max_threads();
		inpar = omp_in_parallel();
		dynamic = omp_get_dynamic();
		nested = omp_get_nested();

		// Print environment information
		printf("Number of processors = %d\n", procs);
		printf("Number of threads = %d\n", nthreads);
		printf("Max threads = %d\n", maxt);
		printf("In parallel? = %d\n", inpar);
		printf("Dynamic threads enabled? = %d\n", dynamic);
		printf("Nested parallelism supported? = %d\n", nested);
*/
		#pragma omp for //shared(tmpTable)
		for(int i=0; i<tmpTable.rows(); i++){
			//cout << "The number of threads is " << omp_get_num_threads() << endl;
			for (int j=0; j<tmpTable.cols(); j++){
				tmpTable(i,j) = getNewState(i, j);
			}
		}

	}
	board = tmpTable;
}


int LifeGame::countNeighbours(int i, int j, state st) const
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


bool LifeGame::getNewState(int i, int j) const
{
	int aNeigh = countNeighbours(i, j, alive);
	if (aNeigh == 3 && stateOf(i,j) == dead){
		return alive;
	}
	else if(stateOf(i,j) == alive && (aNeigh == 2 || aNeigh == 3) ){
		return alive;
	}

	return dead;
}


bool LifeGame::stateOf(int i, int j) const
{
	int newI, newJ;
	if(i<0){
		newI = (NumRows-(abs(i)%NumRows) ) % NumRows;
	}
	else{
		newI = i%NumRows;
	}

	if(j<0){
		newJ = (NumCols-(abs(j)%NumCols)) % NumCols;
	}
	else{
		newJ = j%NumCols;
	}

	return board(newI,newJ);
}


ostream& operator<<(ostream& os, const LifeGame& lg)
{
	cout << lg.board << endl;
    return os;
}

