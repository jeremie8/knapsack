//
// Created by jerem on 2020-04-12.
//

#include <algorithm>
#include "../header/greedy.h"

Output Greedy::solve(const Input &input) {
    std::sort(input.items, input.items+input.nbItems, Item::compareVal);

    //a trivial Greedy algorithm for filling the knapsack
    // it takes nbItems in-order until the knapsack is full
    int value = 0;
    int weight = 0;
    for (int i = 0; i < input.nbItems; i++) {
        if (weight + input.items[i].weight <= input.capacity) {
            input.items[i].taken = 1;
            value += input.items[i].value;
            weight += input.items[i].weight;
        } else {
            input.items[i].taken = 0;
        }
    }

    std::sort(input.items, input.items+input.nbItems, Item::compareIndex);

    return {input.nbItems, input.items, value};
}
