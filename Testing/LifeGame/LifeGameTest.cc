/*============================================================================

  research-computing-with-cpp-demo: CMake based demo code.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

============================================================================*/

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch.hpp>
#include <string>

#include <LifeGame.hpp>
#include <GeneralException.hpp>
#include <IncorrectInitialEstimateException.hpp>
#include <IncorrectSizesException.hpp>
#include <NoFileFoundException.hpp>

using namespace std;

TEST_CASE( "Input file bad formatting", "[Input File]" ) {

    string input_path = "../../../Data/data.lg";

    SECTION("Checking that a wrong file gives me error"){
        	REQUIRE_THROWS_AS(LifeGame<bool> lg("../../"), NoFileFoundException );
     }

    SECTION("Checking that the sizes are correct"){
    	string incorrect_sizes_path = "../../../Data/dataIncorrectSizes.lg";
    	REQUIRE_THROWS_AS(LifeGame<bool> lg(incorrect_sizes_path), IncorrectSizesException );
    }

    SECTION("Incorrect initial estimate"){
       		string incorrect_ie_path = "../../../Data/dataIncorrectInitialEstimate.lg";
           	REQUIRE_THROWS_AS(LifeGame<bool> lg(incorrect_ie_path), IncorrectInitialEstimateException );
    }
}





