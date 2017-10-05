#ifndef BOARD_FILE_MANAGER_H
#define BOARD_FILE_MANAGER_H

#include <string>
#include <fstream>
#include "general.hpp"

using namespace std;

class BoardFileManager
{  
    public:
    static void loadFile(const string, Board&);
    static void writeInFile(const string outputPath, const Board& b);
    static ifstream openFileCorrectly(const string inputPath);
    static void establishBoardSizeFromHeaders(istream& file, Board& b);
    static int getSizeFromLine(std::string line);
    static bool readValueFromLine(istringstream& iss);
    static string tryToRead(istringstream& iss);
    static bool tryToMakeSenseOfTheDatum(const string datumRead);
    static void readBoardFromFile(ifstream& file, Board& board);
    static void readBoardLineFromFile(const string, Board&, const int whichLine);
    static void validateDataInFile(const string line);

};

#endif
