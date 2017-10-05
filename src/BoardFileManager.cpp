#include "BoardFileManager.hpp"
#include "GeneralException.hpp"

using namespace std;

void BoardFileManager::loadFile(const string inputPath, Board& b){
    ifstream file = BoardFileManager::openFileCorrectly(inputPath);
    BoardFileManager::readBoardFromFile(file, b);
}

void BoardFileManager::validateDataInFile(const string line){
    if (line.size() == 0) throw GeneralException("No data");
}

void BoardFileManager::readBoardLineFromFile(const string line, Board& board, const int whichLine){
    istringstream iss(line);
    int nCols = board.cols();
    for(int i=0; i < nCols; i++){
        board(whichLine, i) = BoardFileManager::readValueFromLine(iss);
    }
}

void BoardFileManager::readBoardFromFile(ifstream& file, Board& board){
    int nRows = board.rows();
    string line;

    getline(file, line);

    BoardFileManager::validateDataInFile(line);

    for (int i=0; i<nRows; i++){
        BoardFileManager::readBoardLineFromFile(line, board, i);
    }
}

bool BoardFileManager::readValueFromLine(istringstream& iss){
    string stringBool = tryToRead(iss);
    return BoardFileManager::tryToMakeSenseOfTheDatum(stringBool);
}

string BoardFileManager::tryToRead(istringstream& iss){
    string temp;
    if (!(iss >> temp)) throw GeneralException("Not enough data");
}

bool BoardFileManager::tryToMakeSenseOfTheDatum(const string datumRead){
    int integerTemp;
    integerTemp = atoi(datumRead.c_str());
    if ( (integerTemp != 1) && (integerTemp != 0) ) throw GeneralException("Value not allowed");

    return (integerTemp == 1);
}

ifstream BoardFileManager::openFileCorrectly(const string inputPath){
    ifstream file(inputPath.c_str());
    if(!file.is_open()) throw GeneralException("No File Found");
    return file;
}

void BoardFileManager::establishBoardSizeFromHeaders(istream& file, Board& board){
    string line;
    getline(file, line);
    int nRows = BoardFileManager::getSizeFromLine(line);
    getline(file, line);
    int nCols = BoardFileManager::getSizeFromLine(line);

    board.resize(nRows, nCols);
}

int BoardFileManager::getSizeFromLine(string line){
    if (line.size() == 0) throw GeneralException("Incorrect Sizes");
    return atoi(line.c_str());
}

void BoardFileManager::writeInFile(string outputPath, const Board& board){
    ofstream myfile;
    myfile.open(outputPath.c_str(), std::ios_base::app);
    myfile << board << endl << endl;
    myfile.close();
}
