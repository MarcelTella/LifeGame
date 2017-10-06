/*============================================================================

  research-computing-with-cpp-demo: CMake based demo code.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

============================================================================*/
#include <iostream>
#include <Eigen/Dense>
#include "LifeGame.hpp"
#include "GeneralException.hpp"
#include "commandLineUtilities.hpp"

int main(int argc, char** argv){
    int iterations;
    string inputPath, outputPath;
    if(!programOptions(argc, argv, inputPath, outputPath, iterations))
        return EXIT_FAILURE;

    LifeGame lifegame(inputPath);
    lifegame.writeInFile(outputPath);
    for (int i = 0; i<iterations; i++){
        lifegame.updateBoard();
        lifegame.writeInFile(outputPath);
    }

    return EXIT_SUCCESS;
}
