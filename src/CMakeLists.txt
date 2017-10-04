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
set(EXECUTABLE_OUTPUT_PATH "bin")

set(SOURCES
    main.cpp
    LifeGame.hpp
    LifeGame.cpp
    GeneralException.hpp
    IncorrectInitialStateException.hpp
    IncorrectSizesException.hpp
    NoFileFoundException.hpp
)

add_executable(LifeGame ${SOURCES})
target_link_libraries(LifeGame ${ITK_LIBRARIES} ${Boost_LIBRARIES})

