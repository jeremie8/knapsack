//
// Created by jerem on 2020-04-12.
//

#include "../header/dp.h"
#include <algorithm>

using namespace std;

Output Dp::solve(const Input &input) {
    //initialize
    int **table = new int *[input.nbItems + 1];
    for (int i = 0; i <= input.nbItems; i++) {
        table[i] = new int[input.capacity + 1];
    }
    //at nb items = 0, value = 0 for all weights
    for (int i = 0; i <= input.capacity; i++) {
        table[0][i] = 0;
    }

    //populate table
    for (int curItem = 0; curItem < input.nbItems; curItem++) {
        int weightCurItem = input.items[curItem].weight;
        int valueCurItem = input.items[curItem].value;
        for (int curWeight = 0; curWeight <= input.capacity; curWeight++) {
            int value = 0;
            if (weightCurItem <= curWeight) {
                value = max(table[curItem][curWeight], table[curItem][curWeight - weightCurItem] + valueCurItem);
            } else {
                value = table[curItem][curWeight];
            }
            table[curItem + 1][curWeight] = value;
        }
    }

    //taken
    int value = table[input.nbItems][input.capacity];
    int curWeight = input.capacity;
    for (int curItem = input.nbItems; curItem > 0; curItem--) {
        if(table[curItem][curWeight] != table[curItem - 1][curWeight]){
            input.items[curItem - 1].taken = 1;
            curWeight -= input.items[curItem - 1].weight;
        }
    }
    return Output(input.nbItems, input.items, value, 1);
}
