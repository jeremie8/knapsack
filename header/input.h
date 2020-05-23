//
// Created by jerem on 2020-04-12.
//

#ifndef SOLVER_INPUT_H
#define SOLVER_INPUT_H


#include "item.h"

struct Input {
    int nbItems;
    int capacity;
    Item* items;
    Input(int nbItems, int capacity, Item* items): nbItems(nbItems), capacity(capacity), items(items){}
    Input(){};
};


#endif //SOLVER_INPUT_H
