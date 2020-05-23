//
// Created by jerem on 2020-04-12.
//

#include <algorithm>
#include <utility>
#include "../header/branching.h"
#include <stack>


int curBest;
vector<int> indexesToTakeBest;
Input input;

Output Branching::makeOutput() {
    int curInd = 0;
    for(int i = 0; i < input.nbItems; i++){
        input.items[i].taken = 0;
    }
    for(int i : indexesToTakeBest){
        input.items[i].taken = 1;
    }
    return Output(input.nbItems, input.items, curBest, 1);
}

struct Node{
    float max;
    int value;
    int leftOverWeight;
    int index;
    vector<int> indToTake;

    Node(float max, int value, int leftOverWeight, int index, const vector<int> indToTake) : max(max), value(value),
                                                                                              leftOverWeight(
                                                                                                      leftOverWeight),
                                                                                              index(index),
                                                                                              indToTake(indToTake) {}
};
Output Branching::solve(const Input &theInput) {
    input = theInput;
    float relaxValue = calculateRelaxValue();
    curBest = 0;

    vector<int> v;

    std::stack<Node> nodes;
    nodes.push(Node(relaxValue, 0, input.capacity, -1, v));
    while(!nodes.empty()){
        Node curNode = nodes.top();
        nodes.pop();

        if(curNode.max < curBest || curNode.leftOverWeight < 0) continue;
        if(curNode.index == input.nbItems - 1){
            if(curNode.value > curBest){
                curBest = curNode.value;
                indexesToTakeBest = move(curNode.indToTake);
            }
            continue;
        }

        Item next = input.items[curNode.index + 1];

        //take next
        curNode.indToTake.push_back(curNode.index + 1);
        nodes.push(Node(curNode.max, curNode.value + next.value, curNode.leftOverWeight - next.weight, curNode.index + 1, curNode.indToTake));

        curNode.indToTake.pop_back();
        //dont take next
        nodes.push(Node(curNode.max - next.val, curNode.value, curNode.leftOverWeight, curNode.index + 1, curNode.indToTake));
    }

    //recSolve(relaxValue, 0, 0, -1, indexesToTakeBest);
    return makeOutput();
}

float Branching::calculateRelaxValue() {
    //calculate relaxation value if fraction
    std::sort(input.items, input.items+input.nbItems, Item::compareVal);

    //a trivial Greedy algorithm for filling the knapsack
    // it takes nbItems in-order until the knapsack is full
    float relaxValue = 0;
    int weight = 0;
    for (int i = 0; i < input.nbItems; i++) {
        if (weight + input.items[i].weight <= input.capacity) {
            relaxValue += (float)input.items[i].value;
            weight += input.items[i].weight;
            input.items[i].val = input.items[i].value;
        } else {
            input.items[i].val = (input.items[i].val * (float)(input.capacity - weight));
            relaxValue += input.items[i].val;
            break;
        }
    }

    std::sort(input.items, input.items+input.nbItems, Item::compareIndex);
    return relaxValue;
}
