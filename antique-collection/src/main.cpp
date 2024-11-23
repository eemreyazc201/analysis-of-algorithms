#include "methods.h"

int main() {
    clock_t start, end;

    double SMALL_COUNTING_SORT;
    double SMALL_RARITY_CALCULATION;
    double SMALL_HEAP_SORT;

    double MEDIUM_COUNTING_SORT;
    double MEDIUM_RARITY_CALCULATION;
    double MEDIUM_HEAP_SORT;

    double LARGE_COUNTING_SORT;
    double LARGE_RARITY_CALCULATION;
    double LARGE_HEAP_SORT;

    std::vector<Item> small = readItemsFromFile("../data/items_s.csv");
    std::vector<Item> medium = readItemsFromFile("../data/items_m.csv");
    std::vector<Item> large = readItemsFromFile("../data/items_l.csv");

    start = clock(); small = countingSort(small, "age", true); end = clock(); SMALL_COUNTING_SORT = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "SMALL_COUNTING_SORT: " << SMALL_COUNTING_SORT << " ms" << std::endl;
    start = clock(); calculateRarityScores(small); end = clock(); SMALL_RARITY_CALCULATION = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "SMALL_RARITY_CALCULATION: " << SMALL_RARITY_CALCULATION << " ms" << std::endl;
    start = clock(); heapSortByRarity(small, true); end = clock(); SMALL_HEAP_SORT = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "SMALL_HEAP_SORT: " << SMALL_HEAP_SORT << " ms" << std::endl;

    start = clock(); medium = countingSort(medium, "age", true); end = clock(); MEDIUM_COUNTING_SORT = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "MEDIUM_COUNTING_SORT: " << MEDIUM_COUNTING_SORT << " ms" << std::endl;
    start = clock(); calculateRarityScores(medium); end = clock(); MEDIUM_RARITY_CALCULATION = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "MEDIUM_RARITY_CALCULATION: " << MEDIUM_RARITY_CALCULATION << " ms" << std::endl;
    start = clock(); heapSortByRarity(medium, true); end = clock(); MEDIUM_HEAP_SORT = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "MEDIUM_HEAP_SORT: " << MEDIUM_HEAP_SORT << " ms" << std::endl;

    start = clock(); large = countingSort(large, "age", true); end = clock(); LARGE_COUNTING_SORT = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "LARGE_COUNTING_SORT: " << LARGE_COUNTING_SORT << " ms" << std::endl;
    start = clock(); calculateRarityScores(large); end = clock(); LARGE_RARITY_CALCULATION = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "LARGE_RARITY_CALCULATION: " << LARGE_RARITY_CALCULATION << " ms" << std::endl;
    start = clock(); heapSortByRarity(large, true); end = clock(); LARGE_HEAP_SORT = (((double) (end - start)) * 1000) / CLOCKS_PER_SEC; std::cout << "LARGE_HEAP_SORT: " << LARGE_HEAP_SORT << " ms" << std::endl;

    writeItemsToFile("../out/sorted_items_s.csv", small);
    writeItemsToFile("../out/sorted_items_m.csv", medium);
    writeItemsToFile("../out/sorted_items_l.csv", large);

    std::ofstream out("../out/results.txt");
    out << "SMALL_COUNTING_SORT: " << SMALL_COUNTING_SORT << " ms" << std::endl;
    out << "SMALL_RARITY_CALCULATION: " << SMALL_RARITY_CALCULATION << " ms" << std::endl;
    out << "SMALL_HEAP_SORT: " << SMALL_HEAP_SORT << " ms" << std::endl;
    out << "MEDIUM_COUNTING_SORT: " << MEDIUM_COUNTING_SORT << " ms" << std::endl;
    out << "MEDIUM_RARITY_CALCULATION: " << MEDIUM_RARITY_CALCULATION << " ms" << std::endl;
    out << "MEDIUM_HEAP_SORT: " << MEDIUM_HEAP_SORT << " ms" << std::endl;
    out << "LARGE_COUNTING_SORT: " << LARGE_COUNTING_SORT << " ms" << std::endl;
    out << "LARGE_RARITY_CALCULATION: " << LARGE_RARITY_CALCULATION << " ms" << std::endl;
    out << "LARGE_HEAP_SORT: " << LARGE_HEAP_SORT << " ms" << std::endl;
    out.close();

    return 0;
}