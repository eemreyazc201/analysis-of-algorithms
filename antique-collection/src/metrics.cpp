#include "methods.h"

int getMax (std::vector<Item>& items, const std::string& attribute) {
    int max = 0;

    if (attribute == "age") {for (Item item : items) {if (item.age > max) {max = item.age;}}}
    else if (attribute == "type") {for (Item item : items) {if (item.type > max) {max = item.type;}}}
    else if (attribute == "origin") {for (Item item : items) {if (item.origin > max) {max = item.origin;}}}
    else if (attribute == "rarityScore") {for (Item item : items) {if (item.rarityScore > max) {max = item.rarityScore;}}}
    else {std::cerr << "Invalid attribute: " << attribute << std::endl;}
    
    return max;
}

void calculateRarityScores (std::vector<Item>& items, int ageWindow) {
    int ageMax = items[items.size() - 1].age;
    std::vector<int> count(ageMax + 1, 0);

    // instead of O(n^2), we achieve O(n + ageMax) by using cumulative indexing method, because we know items are sorted by age
    for (int i = 0; i < items.size(); i++) {count[items[i].age]++;}
    for (int i = 1; i <= ageMax; i++) {count[i] += count[i - 1];}

    for (Item& item : items) {
        int min = (item.age <= ageWindow) ? 0 : item.age - ageWindow;
        int max = (item.age + ageWindow >= ageMax) ? ageMax : item.age + ageWindow;
        int minIndex = (min == 0) ? 0 : count[min - 1];
        int maxIndex = count[max] - 1;

        int countSimilar = 0;
        int countTotal = maxIndex - minIndex + 1;
        for (int i = minIndex; i <= maxIndex; i++) {
            if (items[i].type == item.type && items[i].origin == item.origin) {countSimilar++;}
        }

        double probability = (countTotal <= 0) ? 0 : (double)countSimilar / countTotal;
        item.rarityScore = (1 - probability) * (1 + (double)item.age / ageMax);
    }
}