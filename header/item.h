//
// Created by jerem on 2020-04-12.
//

#ifndef SOLVER_ITEM_H
#define SOLVER_ITEM_H


struct Item {
    int value;
    int weight;
    int index;
    float val;
    int taken;

    Item(int value, int weight, int index);

    Item() = default;

    bool operator==(const Item &i);

    bool operator!=(const Item &i);

    static bool compareIndex(const Item& item1, const Item& item2);
    static bool compareVal(const Item& item1, const Item& item2);

};


#endif //SOLVER_ITEM_H
