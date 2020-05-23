//
// Created by jerem on 2020-04-12.
//

#ifndef SOLVER_OUTPUT_H
#define SOLVER_OUTPUT_H


#include "item.h"

struct Output {
    int nbItems;
    Item* items;
    int value;
    int optimal = 0;

    Output(int nbItems, Item *items, int value, int optimal = 0);
    Output() = default;
};


#endif //SOLVER_OUTPUT_H
