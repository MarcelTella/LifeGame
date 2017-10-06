#define CATCH_CONFIG_MAIN
#include <string>
#include "catch.hpp"
#include <string>
#include "../src/LifeGame.hpp"
#include "../src/general.hpp"
#include "../src/LifeGameTestClass.hpp"
#include "../src/GeneralException.hpp"

using namespace std;

TEST_CASE("Testing the state of a cell", "[LifeGame]"){
    {
        Eigen::Matrix<bool, 3, 3> b;
        b << dead, dead,   dead,
             dead, alive,  dead,
             dead, dead,   dead;
        LifeGameTestClass lifeGame = LifeGameTestClass(b);

        REQUIRE(lifeGame.stateOf(0, 0) == dead);
        REQUIRE(lifeGame.stateOf(0, 1) == dead);
        REQUIRE(lifeGame.stateOf(0, 2) == dead);
        REQUIRE(lifeGame.stateOf(1, 0) == dead);
        REQUIRE(lifeGame.stateOf(1, 1) == alive);
        REQUIRE(lifeGame.stateOf(1, 2) == dead);
        REQUIRE(lifeGame.stateOf(2, 0) == dead);
        REQUIRE(lifeGame.stateOf(2, 1) == dead);
        REQUIRE(lifeGame.stateOf(2, 2) == dead);
    }

    {
        Eigen::Matrix<bool, 3, 3> b;
        b << alive,  dead,   alive,
             alive,  alive,  alive,
             dead,   dead,   alive;
        LifeGameTestClass lifeGame = LifeGameTestClass(b);

        REQUIRE(lifeGame.stateOf(0, 0) == alive);
        REQUIRE(lifeGame.stateOf(0, 1) == dead);
        REQUIRE(lifeGame.stateOf(0, 2) == alive);
        REQUIRE(lifeGame.stateOf(1, 0) == alive);
        REQUIRE(lifeGame.stateOf(1, 1) == alive);
        REQUIRE(lifeGame.stateOf(1, 2) == alive);
        REQUIRE(lifeGame.stateOf(2, 0) == dead);
        REQUIRE(lifeGame.stateOf(2, 1) == dead);
        REQUIRE(lifeGame.stateOf(2, 2) == alive);
    }
}

TEST_CASE("Count neighbours alive and dead", "[LifeGame]"){
    Eigen::Matrix<bool, 3, 3> b;
    b << alive,  dead,   alive,
         alive,  alive,  alive,
         dead,   dead,   alive;
    LifeGameTestClass lifeGame = LifeGameTestClass(b);

    REQUIRE(lifeGame.countNeighboursAlive(0, 0) == 5);
    REQUIRE(lifeGame.countNeighboursAlive(0, 1) == 6);
    REQUIRE(lifeGame.countNeighboursAlive(0, 2) == 5);
    REQUIRE(lifeGame.countNeighboursAlive(1, 0) == 5);
    REQUIRE(lifeGame.countNeighboursAlive(1, 1) == 5);
    REQUIRE(lifeGame.countNeighboursAlive(1, 2) == 5);
    REQUIRE(lifeGame.countNeighboursAlive(2, 0) == 6);
    REQUIRE(lifeGame.countNeighboursAlive(2, 1) == 6);
    REQUIRE(lifeGame.countNeighboursAlive(2, 2) == 5);

    REQUIRE(lifeGame.countNeighboursDead(0, 0) == 3);
    REQUIRE(lifeGame.countNeighboursDead(0, 1) == 2);
    REQUIRE(lifeGame.countNeighboursDead(0, 2) == 3);
    REQUIRE(lifeGame.countNeighboursDead(1, 0) == 3);
    REQUIRE(lifeGame.countNeighboursDead(1, 1) == 3);
    REQUIRE(lifeGame.countNeighboursDead(1, 2) == 3);
    REQUIRE(lifeGame.countNeighboursDead(2, 0) == 2);
    REQUIRE(lifeGame.countNeighboursDead(2, 1) == 2);
    REQUIRE(lifeGame.countNeighboursDead(2, 2) == 3);
}

TEST_CASE( "Core conditions, getting a new state from a board and a position", "[LifeGame]" )
{
    // 1. Checking every new state independently.
    Eigen::Matrix<bool, 3, 3> b;
    b << alive,  dead,   dead,
         alive,  alive,  dead,
         alive,  dead,   dead;
    LifeGameTestClass lifeGame = LifeGameTestClass(b);

    REQUIRE(lifeGame.getNewState(0, 0) == alive);
    REQUIRE(lifeGame.getNewState(0, 1) == dead);
    REQUIRE(lifeGame.getNewState(0, 2) == dead);
    REQUIRE(lifeGame.getNewState(1, 0) == alive);
    REQUIRE(lifeGame.getNewState(1, 1) == alive);
    REQUIRE(lifeGame.getNewState(1, 2) == dead);
    REQUIRE(lifeGame.getNewState(2, 0) == alive);
    REQUIRE(lifeGame.getNewState(2, 1) == dead);
    REQUIRE(lifeGame.getNewState(2, 2) == dead);

    // 2. Updating the board and checking the state afterwords
    lifeGame.updateBoard();
    REQUIRE(lifeGame.stateOf(0, 0) == alive);
    REQUIRE(lifeGame.stateOf(0, 1) == dead);
    REQUIRE(lifeGame.stateOf(0, 2) == dead);
    REQUIRE(lifeGame.stateOf(1, 0) == alive);
    REQUIRE(lifeGame.stateOf(1, 1) == alive);
    REQUIRE(lifeGame.stateOf(1, 2) == dead);
    REQUIRE(lifeGame.stateOf(2, 0) == alive);
    REQUIRE(lifeGame.stateOf(2, 1) == dead);
    REQUIRE(lifeGame.stateOf(2, 2) == dead);
}

void tryToCreateWrongPathLifeGame(){
    LifeGame lg("../../wrongFile.lg");
}

void throwExceptionBecauseNoSizesInFile(){
    string incorrectSizesPath = "/tmp/incorrectSizesPath.lg";
    ofstream o;
    o.open(incorrectSizesPath.c_str());
    o << endl << endl;
    o << 1 << 1 << 1 << endl;
    o << 1 << 1 << 1 << endl;
    o << 1 << 1 << 1 << endl;
    o.close();

    LifeGame lg(incorrectSizesPath);
}

TEST_CASE( "Input file bad formatting", "[IO]" ) {
    // 1. Wrong file gives error
    REQUIRE_THROWS_AS(tryToCreateWrongPathLifeGame(), GeneralException);

    // 2. Validate corect sizes.
    REQUIRE_THROWS_AS(throwExceptionBecauseNoSizesInFile(), GeneralException);
}

LifeGame readFileSuccessfully(){
    string inputPath = "../data/data.lg";
    Lifegame lg(inputPath);
    return lg;
}

TEST_CASE("Input file read correctly", "[IO]"){

    REQUIRE_NOTHROW(readFileSuccessfully());
    LifeGameTest lg = readFileSuccessfully();
}



//SECTION("Incorrect initial estimate"){

//	string correct_path = "/tmp/correct_path.lg";
//	ofstream o;
//	o.open (correct_path.c_str());
//	o << 3 << endl << 3 << endl;
//	o << 1 << ' ' <<  1 << ' ' << 1 << endl;
//	o << 1 << ' ' <<  1 << ' ' << 1 << endl;
//	o << 1 << ' ' <<  1 << ' ' << 1 << endl;
//	o.close();
//	REQUIRE_NOTHROW(LifeGame lg(correct_path) );
//}

//    SECTION("Incorrect size of the initial estimate"){
//			string incorrect_ie = "/tmp/correct_path.lg";
//			ofstream o;
//			o.open (incorrect_ie.c_str());
//			o << 3 << endl << 3 << endl;
//			o << 1  << ' ' << 1 << endl;
//			o << 1  << ' ' << 1 << endl;
//			o << 1  << ' ' << 1 << endl;

//			REQUIRE_THROWS_AS(LifeGame lg(incorrect_ie) , IncorrectInitialStateException );
//	}
//}
