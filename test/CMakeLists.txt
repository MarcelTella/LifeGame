#/*============================================================================
#
#  research-computing-with-cpp-demo: CMake based demo code.
#
#  Copyright (c) University College London (UCL). All rights reserved.
#
#  This software is distributed WITHOUT ANY WARRANTY; without even
#  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
#  PURPOSE.
#
#  See LICENSE.txt in the top level directory for details.
#
#============================================================================*/
SET(SOURCES
    ../src/LifeGame.hpp
    ../src/LifeGame.cpp
    ../src/LifeGameTestClass.hpp
    ../src/LifeGameTestClass.cpp
    ../src/BoardFileManager.hpp
    ../src/BoardFileManager.cpp

    catch.hpp

    LifeGameTest.cpp
)
add_executable(LifeGameTest ${SOURCES})
target_link_libraries(LifeGameTest ${ITK_LIBRARIES})
