#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/program_options.hpp>

using namespace std;
namespace po = boost::program_options;

struct CLVariables{
    po::variables_map vm;
    po::options_description desc;

    CLVariables(const po::variables_map& vmIn, const po::options_description& descIn) :
        vm(vmIn),
        desc(descIn)
    {}
};

CLVariables generateHelpMessage(int argc, char** argv);
void captureInputParameters(const CLVariables&, string& inputPath,
                       string& outputPath, int& iterations);
int validateNIterations(const int nIters, const CLVariables& clVars);
int validateExactNumOfParameters(const CLVariables&, const int argc);
int isTheUserAskingForHelp(const CLVariables& clVars);
int validateFileExists(const string);
int programOptions(int argc, char** argv, string& inputPath,
                        string& outputPath, int& iterations);
void showHelp(const CLVariables& clVars);
