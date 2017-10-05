#define CATCH_CONFIG_MAIN
#include <string>
#include "catch.hpp"


TEST_CASE( "Dummy test", "[Test]" ) {
    REQUIRE(1 == 1);
}


//TEST_CASE( "Input file bad formatting", "[IO]" ) {

//    string input_path = "../../../Data/data.lg";

//    SECTION("Checking that a wrong file gives me error"){
//        REQUIRE_THROWS_AS(LifeGame lg("../../a.lg"), NoFileFoundException );
//     }

//    SECTION("Checking that the sizes are correct"){
//    	string incorrect_sizes_path = "/tmp/incorrect_path.lg";
//    	ofstream o;
//	o.open (incorrect_sizes_path.c_str());
//    	o << endl << endl;
//    	o << 1 << 1 << 1 << endl;
//	o << 1 << 1 << 1 << endl;
//    	o << 1 << 1 << 1 << endl;
//    	o.close();
//    	REQUIRE_THROWS_AS(LifeGame lg(incorrect_sizes_path), IncorrectSizesException);
//    }


//    SECTION("Incorrect initial estimate"){

//    		string incorrect_ie = "/tmp/incorrect_ie.lg";
//		ofstream o;
//		o.open (incorrect_ie.c_str());
//		o << 3 << endl << 3 << endl;
//		o << 1 << ' ' <<  1 << ' ' << 1 << endl;
//		o << 1 << ' ' <<  2 << ' ' << 1 << endl;
//		o << 1 << ' ' <<  1 << ' ' << 1 << endl;
//		o.close();
//       		REQUIRE_THROWS_AS(LifeGame lg(incorrect_ie), IncorrectInitialStateException );
//    }


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

//TEST_CASE( "Checking the count of neighbours", "[Life Game]" ) {

//	string correct_path = "/tmp/correct_x.lg";
//	ofstream o;
//	o.open (correct_path.c_str());
//	o << 3 << endl << 3 << endl;
//	o << 1 << ' ' <<  1 << ' ' << 1 << endl;
//	o << 1 << ' ' <<  1 << ' ' << 1 << endl;
//	o << 1 << ' ' <<  1 << ' ' << 1 << endl;
//	o.close();
//	LifeGame lg(correct_path);

//	REQUIRE( lg.countNeighbours(1,1,alive) == 8);

//	o.open (correct_path.c_str());
//	o << 3 << endl << 3 << endl;
//	o << 0 << ' ' <<  1 << ' ' << 1 << endl;
//	o << 1 << ' ' <<  1 << ' ' << 1 << endl;
//	o << 1 << ' ' <<  1 << ' ' << 1 << endl;
//	o.close();
//	lg.loadFile(correct_path);
//	REQUIRE( lg.countNeighbours(1,1,alive) == 7);

//	o.open (correct_path.c_str());
//	o << 3 << endl << 3 << endl;
//	o << 0 << ' ' <<  1 << ' ' << 1 << endl;
//	o << 0 << ' ' <<  1 << ' ' << 1 << endl;
//	o << 1 << ' ' <<  1 << ' ' << 1 << endl;
//	o.close();
//	lg.loadFile(correct_path);
//	REQUIRE( lg.countNeighbours(1,1,alive) == 6);

//	o.open (correct_path.c_str());
//	o << 3 << endl << 3 << endl;
//	o << 0 << ' ' <<  1 << ' ' << 1 << endl;
//	o << 0 << ' ' <<  1 << ' ' << 1 << endl;
//	o << 0 << ' ' <<  1 << ' ' << 1 << endl;
//	o.close();
//	lg.loadFile(correct_path);
//	REQUIRE( lg.countNeighbours(1,1,alive) == 5);

//	o.open (correct_path.c_str());
//	o << 3 << endl << 3 << endl;
//	o << 0 << ' ' <<  1 << ' ' << 1 << endl;
//	o << 0 << ' ' <<  1 << ' ' << 1 << endl;
//	o << 0 << ' ' <<  0 << ' ' << 1 << endl;
//	o.close();
//	lg.loadFile(correct_path);
//	REQUIRE( lg.countNeighbours(1,1,alive) == 4);

//	o.open (correct_path.c_str());
//	o << 3 << endl << 3 << endl;
//	o << 0 << ' ' <<  1 << ' ' << 1 << endl;
//	o << 0 << ' ' <<  1 << ' ' << 1 << endl;
//	o << 0 << ' ' <<  0 << ' ' << 0 << endl;
//	o.close();
//	lg.loadFile(correct_path);
//	REQUIRE( lg.countNeighbours(1,1,alive) == 3);

//	o.open (correct_path.c_str());
//	o << 3 << endl << 3 << endl;
//	o << 0 << ' ' <<  1 << ' ' << 1 << endl;
//	o << 0 << ' ' <<  1 << ' ' << 0 << endl;
//	o << 0 << ' ' <<  0 << ' ' << 0 << endl;
//	o.close();
//	lg.loadFile(correct_path);
//	REQUIRE( lg.countNeighbours(1,1,alive) == 2);

//	o.open (correct_path.c_str());
//	o << 3 << endl << 3 << endl;
//	o << 0 << ' ' <<  1 << ' ' << 0 << endl;
//	o << 0 << ' ' <<  1 << ' ' << 0 << endl;
//	o << 0 << ' ' <<  0 << ' ' << 0 << endl;
//	o.close();
//	lg.loadFile(correct_path);
//	REQUIRE( lg.countNeighbours(1,1,alive) == 1);

//	// Dead cells
//	o.open (correct_path.c_str());
//	o << 3 << endl << 3 << endl;
//	o << 1 << ' ' <<  1 << ' ' << 1 << endl;
//	o << 1 << ' ' <<  1 << ' ' << 1 << endl;
//	o << 1 << ' ' <<  1 << ' ' << 1 << endl;
//	o.close();
//	lg.loadFile(correct_path);
//	REQUIRE( lg.countNeighbours(1,1,dead) == 0);

//	o.open (correct_path.c_str());
//	o << 3 << endl << 3 << endl;
//	o << 0 << ' ' <<  1 << ' ' << 1 << endl;
//	o << 1 << ' ' <<  1 << ' ' << 1 << endl;
//	o << 1 << ' ' <<  1 << ' ' << 1 << endl;
//	o.close();
//	lg.loadFile(correct_path);
//	REQUIRE( lg.countNeighbours(1,1,dead) == 1);

//	o.open (correct_path.c_str());
//	o << 3 << endl << 3 << endl;
//	o << 0 << ' ' <<  1 << ' ' << 1 << endl;
//	o << 0 << ' ' <<  1 << ' ' << 1 << endl;
//	o << 1 << ' ' <<  1 << ' ' << 1 << endl;
//	o.close();
//	lg.loadFile(correct_path);
//	REQUIRE( lg.countNeighbours(1,1,dead) == 2);

//	o.open (correct_path.c_str());
//	o << 3 << endl << 3 << endl;
//	o << 0 << ' ' <<  1 << ' ' << 1 << endl;
//	o << 0 << ' ' <<  1 << ' ' << 1 << endl;
//	o << 0 << ' ' <<  1 << ' ' << 1 << endl;
//	o.close();
//	lg.loadFile(correct_path);
//	REQUIRE( lg.countNeighbours(1,1,dead) == 3);

//	o.open (correct_path.c_str());
//	o << 3 << endl << 3 << endl;
//	o << 0 << ' ' <<  1 << ' ' << 1 << endl;
//	o << 0 << ' ' <<  1 << ' ' << 1 << endl;
//	o << 0 << ' ' <<  0 << ' ' << 1 << endl;
//	o.close();
//	lg.loadFile(correct_path);
//	REQUIRE( lg.countNeighbours(1,1,dead) == 4);

//	o.open (correct_path.c_str());
//	o << 3 << endl << 3 << endl;
//	o << 0 << ' ' <<  1 << ' ' << 1 << endl;
//	o << 0 << ' ' <<  1 << ' ' << 1 << endl;
//	o << 0 << ' ' <<  0 << ' ' << 0 << endl;
//	o.close();
//	lg.loadFile(correct_path);
//	REQUIRE( lg.countNeighbours(1,1,dead) == 5);

//	o.open (correct_path.c_str());
//	o << 3 << endl << 3 << endl;
//	o << 0 << ' ' <<  1 << ' ' << 1 << endl;
//	o << 0 << ' ' <<  1 << ' ' << 0 << endl;
//	o << 0 << ' ' <<  0 << ' ' << 0 << endl;
//	o.close();
//	lg.loadFile(correct_path);
//	REQUIRE( lg.countNeighbours(1,1,dead) == 6);

//	o.open (correct_path.c_str());
//	o << 3 << endl << 3 << endl;
//	o << 0 << ' ' <<  1 << ' ' << 0 << endl;
//	o << 0 << ' ' <<  1 << ' ' << 0 << endl;
//	o << 0 << ' ' <<  0 << ' ' << 0 << endl;
//	o.close();
//	lg.loadFile(correct_path);
//	REQUIRE( lg.countNeighbours(1,1,dead) == 7);

//	o.open (correct_path.c_str());
//	o << 3 << endl << 3 << endl;
//	o << 0 << ' ' <<  0 << ' ' << 0 << endl;
//	o << 0 << ' ' <<  1 << ' ' << 0 << endl;
//	o << 0 << ' ' <<  0 << ' ' << 0 << endl;
//	o.close();
//	lg.loadFile(correct_path);
//	REQUIRE( lg.countNeighbours(1,1,dead) == 8);
//}

//TEST_CASE( "Test for the state of the cells", "[Life Game]" ) {

//	string correct_path = "/tmp/correct_x.lg";
//	ofstream o;
//	o.open (correct_path.c_str());
//	o << 3 << endl << 3 << endl;
//	o << 1 << ' ' <<  0 << ' ' << 1 << endl;
//	o << 1 << ' ' <<  1 << ' ' << 1 << endl;
//	o << 0 << ' ' <<  1 << ' ' << 1 << endl;
//	o.close();
//	LifeGame lg(correct_path);
//	REQUIRE( lg.stateOf(0,0) == true);
//	REQUIRE( lg.stateOf(1,2) == true);
//	REQUIRE( lg.stateOf(-1,0) == false);
//	REQUIRE( lg.stateOf(0,-2) == false);
//	REQUIRE( lg.stateOf(1,-1) == true);

//}


//TEST_CASE( "Core conditions, getting a new state from a board and a position", "[Life Game]" )
//{
//	string correct_path = "/tmp/correct_x.lg";
//	ofstream o;
//	o.open (correct_path.c_str());
//	o << 3 << endl << 3 << endl;
//	o << 1 << ' ' <<  0 << ' ' << 0 << endl;
//	o << 1 << ' ' <<  1 << ' ' << 0 << endl;
//	o << 1 << ' ' <<  0 << ' ' << 0 << endl;
//	o.close();
//	LifeGame lg(correct_path);
//	REQUIRE( lg.getNewState(0,0) == true);
//	REQUIRE( lg.getNewState(0,1) == false);
//	REQUIRE( lg.getNewState(0,2) == false);
//	REQUIRE( lg.getNewState(1,0) == true);
//	REQUIRE( lg.getNewState(1,1) == true);
//	REQUIRE( lg.getNewState(1,2) == false);
//	REQUIRE( lg.getNewState(2,0) == true);
//	REQUIRE( lg.getNewState(2,1) == false);
//	REQUIRE( lg.getNewState(2,2) == false);
//}