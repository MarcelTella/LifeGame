#################################
# Parameters to tune
#################################
path="../research-computing-with-cpp-demo-build" 
dataPath="../../LifeGame/data"
outputDataPath="."
nIters=50;

#################################
# Compile
#################################
mkdir $path
cd $path
cmake ../
make

#################################
# Run tests
#################################
testCommand="./$path/bin/LifeGameTest"
echo "running Tests as $testCommand" 
$testCommand

#################################
# Run Example
#################################
runExampleCommand="./$path/bin/LifeGame --in $dataPath/init100.txt --out $outputDataPath/output.txt --iter $nIters"
echo "running Example as $runExampleCommand" 
$runExampleCommand


