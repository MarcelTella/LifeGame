#ifndef GENERAL_H
#define GENERAL_H

#include <Eigen/Dense>
#include <string>

enum state {dead, alive};
enum dimension {rows, cols};

typedef Eigen::Matrix<bool, Eigen::Dynamic, Eigen::Dynamic> Board;

const std::string TEST_DATA_PATH = "/home/marcel/LifeGame/data/";
#endif
