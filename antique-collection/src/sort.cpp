#include "methods.h"

std::vector<Item> countingSort (std::vector<Item>& items, const std::string& attribute, bool ascending) {
    int max = getMax(items, attribute);
    std::vector<int> count(max + 1, 0);
    std::vector<Item> output(items.size());
    
    if (attribute == "age") {
        for (int i = 0; i < items.size(); i++) {count[items[i].age]++;}
        if (ascending) {for (int i = 1; i <= max; i++) {count[i] += count[i - 1];}} // make cumulative sum left to right, if ascending
        else {for (int i = max - 1; i >= 0; i--) {count[i] += count[i + 1];}} // make cumulative sum right to left, if descending
        for (int i = items.size() - 1; i >= 0; i--) {
            output[count[items[i].age] - 1] = items[i];
            count[items[i].age]--;
        } return output;
    } else if (attribute == "type") {
        for (int i = 0; i < items.size(); i++) {count[items[i].type]++;}
        if (ascending) {for (int i = 1; i <= max; i++) {count[i] += count[i - 1];}} // make cumulative sum left to right, if ascending
        else {for (int i = max - 1; i >= 0; i--) {count[i] += count[i + 1];}} // make cumulative sum right to left, if descending
        for (int i = items.size() - 1; i >= 0; i--) {
            output[count[items[i].type] - 1] = items[i];
            count[items[i].type]--;
        } return output;        
    } else if (attribute == "origin") {
        for (int i = 0; i < items.size(); i++) {count[items[i].origin]++;}
        if (ascending) {for (int i = 1; i <= max; i++) {count[i] += count[i - 1];}} // make cumulative sum left to right, if ascending
        else {for (int i = max - 1; i >= 0; i--) {count[i] += count[i + 1];}} // make cumulative sum right to left, if descending
        for (int i = items.size() - 1; i >= 0; i--) {
            output[count[items[i].origin] - 1] = items[i];
            count[items[i].origin]--;
        } return output;
    } else {std::cerr << "Invalid attribute\n"; return items;} // rarityScore is double, so it is not possible to sort by it using counting sort
}

void heapify (std::vector<Item>& items, int n, int i, bool descending) {
    int rightChild = 2 * i + 2; int leftChild = 2 * i + 1; int toBeSwapped = i; 
    if (leftChild < n && ((items[leftChild].rarityScore > items[i].rarityScore && !descending) || (items[leftChild].rarityScore < items[i].rarityScore && descending))) {toBeSwapped = leftChild;}
    if (rightChild < n && ((items[rightChild].rarityScore > items[toBeSwapped].rarityScore && !descending) || (items[rightChild].rarityScore < items[toBeSwapped].rarityScore && descending))) {toBeSwapped = rightChild;}
    if (toBeSwapped != i) {
        Item temp = items[i]; items[i] = items[toBeSwapped]; items[toBeSwapped] = temp;
        heapify(items, n, toBeSwapped, descending);
    }
}

std::vector<Item> heapSortByRarity (std::vector<Item>& items, bool descending) {
    int n = items.size();
    for (int i = n / 2 - 1; i >= 0; i--) {heapify(items, n, i, descending);} // build heap
    for (int i = n - 1; i > 0; i--) {
        Item temp = items[0]; items[0] = items[i]; items[i] = temp; // put maximum element at the end
        heapify(items, i, 0, descending); // heapify reduced heap
    } return items;
}