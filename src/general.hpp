#ifndef GENERAL_H
#define GENERAL_H

#include <Eigen/Dense>

enum state {dead, alive};
enum dimension {rows, cols};

typedef Eigen::Matrix<bool, Eigen::Dynamic, Eigen::Dynamic> Board;

#endif
