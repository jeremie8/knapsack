#include <iostream>
#include<bits/stdc++.h>
#include "header/item.h"
#include "header/input.h"
#include "header/output.h"
#include "header/greedy.h"
#include "header/dp.h"
#include "header/branching.h"

using namespace std;

Input parseInput()
{
    int nbItems, capacity;
    cin >> nbItems >> capacity;
    Item* items = new Item[nbItems];
    int value = 0;
    int weight = 0;

    for (int i = 0; i < nbItems; i++) {
        cin >> value >> weight;
        items[i] = Item(value, weight, i);
    }
    return {nbItems, capacity, items};
}

void out(const Output& output) {
    cout << output.value << " "<<output.optimal<<"\n";
    for (int i = 0; i < output.nbItems; i++) {
        cout << output.items[i].taken << " ";
    }
    cout << endl;
}

int main() {
    try {
        Input input = parseInput();
        Output output{};
        if(input.nbItems < 100)
            output = Branching::solve(input);
        else
            output = Branching::solve(input);
        out(output);
    } catch (exception &e) {
        cout << e.what();
    }
}
