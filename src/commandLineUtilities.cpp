#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <sys/stat.h>
#include <boost/lexical_cast.hpp>
#include <boost/program_options.hpp>
#include "GeneralException.hpp"
#include "commandLineUtilities.hpp"

using namespace std;
namespace po = boost::program_options;

CLVariables generateHelpMessage(int argc, char** argv){
    po::options_description desc("Allowed options");
    desc.add_options()
            ("help", "Produces help message")
            ("in", po::value<std::string> (), "Input file")
            ("out", po::value<std::string> (), "Output file")
            ("iter", po::value<std::string> (), "Number of Iterations");

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    CLVariables clVars(vm, desc);
    return clVars;
}

void captureInputParameters(const CLVariables& clVars, string& inputPath,
                       string& outputPath, int& iterations){
    po::variables_map vm = clVars.vm;
    if(vm.count("in")){
        inputPath = vm["in"].as<string>();
    }

    if(vm.count("out")){
        outputPath = vm["out"].as<string>();
    }

    if(vm.count("iter")){
        iterations = atoi(vm["iter"].as<string>().c_str());
    }
}

int validateNIterations(const int nIters, const CLVariables& clVars){
    if(nIters < 0){
        showHelp(clVars);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int validateExactNumOfParameters(const CLVariables& clVars, const int argc){
    if (argc != 7 || ( !clVars.vm.count("in")  || !clVars.vm.count("out")
                       || !clVars.vm.count("iter") ) ) {
        showHelp(clVars);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int isTheUserAskingForHelp(const CLVariables& clVars){
    if(clVars.vm.count("help")){
        showHelp(clVars);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int validateFileExists(const string path){
    struct stat buffer;
    if(stat(path.c_str(), &buffer) == 0)
        return EXIT_SUCCESS;
    return EXIT_FAILURE;
}

int programOptions(int argc, char** argv, string& inputPath,
                        string& outputPath, int& iterations){
    CLVariables clVars = generateHelpMessage(argc, argv);
    if (isTheUserAskingForHelp(clVars) == EXIT_FAILURE) return EXIT_FAILURE;
    if (validateExactNumOfParameters(clVars, argc) == EXIT_FAILURE) return EXIT_FAILURE;

    captureInputParameters(clVars, inputPath, outputPath, iterations);
    if (validateNIterations(iterations, clVars) == EXIT_FAILURE) return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

void showHelp(const CLVariables& clVars){
    cout << clVars.desc << "\n";
}
