/*============================================================================

  research-computing-with-cpp-demo: CMake based demo code.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

============================================================================*/

#include <cstdlib>
#include <iostream>
#include <Eigen/Dense>
#include <boost/lexical_cast.hpp>
#include <boost/program_options.hpp>
#include <itkImage.h>
#include <LifeGame.hpp>

using namespace std;

namespace po = boost::program_options;

int program_options (int argc, char** argv, string &path1, string &output_path, int &iter)
{
	po::options_description desc("Allowed options");

	desc.add_options()
	    ("help", "produce help message")
	    ("in", po::value<std::string> (), "Input file")
	    ("out", po::value<std::string> (), "Output file")
	    ("iter", po::value<std::string> (), "Number of Iterations")
	;

	po::variables_map vm;
	po::store(po::parse_command_line(argc, argv, desc), vm);
	po::notify(vm);

	//Discarting execution#
	if (vm.count("help") || argc != 7 || ( !vm.count("in")  || !vm.count("out") || !vm.count("iter") ) ) {
		cout << desc << "\n";
		return 0;
	}

	//Case of incomplete number of parameters, e.g. --out (empty)
	if (argc%2 == 0){
		cout << desc << "\n";
		return 0;
	}

	if (vm.count("in")) {
		path1 = vm["in"].as<string>();
	}

	if (vm.count("out")) {
		output_path = vm["out"].as<string>();
	}

	if (vm.count("iter")) {
		iter = atoi(vm["iter"].as<string>().c_str());
	}

	return 1;
}

int main(int argc, char** argv)
{
	//Get points
	string input_path;
	string output_path;
	int iter;

	if( !program_options(argc, argv, input_path, output_path, iter))
		return 1;

	if(iter < 0) throw GeneralException("Negative number of iterations");
	//Initialise lg;
	LifeGame<bool> lg(input_path);

	//while(true){
	lg.writeInFile(output_path);
	for (int i=0;i<iter;i++){
		lg.updateBoard();
		lg.writeInFile(output_path);
	}

  return EXIT_SUCCESS;
}
