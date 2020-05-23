//
// Created by jerem on 2020-04-12.
//

#include "../header/item.h"

Item::Item(int value, int weight, int index) {
    this->value = value;
    this->weight = weight;
    this->index = index;
    val = (float) value / (float) weight;
    taken = 0;
}

bool Item::operator==(const Item &i) {
    return this->index == i.index;
}

bool Item::operator!=(const Item &i) {
    return this->index != i.index;
}

bool Item::compareIndex(const Item& item1, const Item& item2){
    return item1.index < item2.index;
}

bool Item::compareVal(const Item& item1, const Item& item2){
    return item1.val > item2.val;
}