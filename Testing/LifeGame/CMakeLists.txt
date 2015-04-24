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

add_executable(LifeGameTest LifeGameTest.cc ${PROJECT_SOURCE_DIR}/Code/LifeGame/LifeGame.cpp)
target_link_libraries(LifeGameTest ${ITK_LIBRARIES})

