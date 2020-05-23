//
// Created by jerem on 2020-04-12.
//

#ifndef SOLVER_BRANCHING_H
#define SOLVER_BRANCHING_H


#include "output.h"
#include "input.h"
#include <vector>

using namespace std;

class Branching {
private:
    static float calculateRelaxValue();
    static Output makeOutput();
public :
    static Output solve(const Input& input);
};


#endif //SOLVER_BRANCHING_H
