#include "methods.h"

std::vector<Item> readItemsFromFile (const std::string& filename) {
    std::vector<Item> items; std::ifstream file (filename); if (file.is_open()) {
        std::string line; std::getline(file, line); while (std::getline(file, line)) {
            std::stringstream ss (line); int age, type, origin; double rarityScore;
            ss >> age; ss.ignore(1, ','); ss >> type; ss.ignore(1, ','); ss >> origin; ss.ignore(1, ','); ss >> rarityScore;
            items.push_back({age, type, origin, rarityScore});
        } file.close();
    } else {std::cerr << "Error: Unable to open file " << filename << std::endl;}
    return items;
}

void writeItemsToFile (const std::string& filename, const std::vector<Item>& items) {
    std::ofstream file (filename); if (file.is_open()) {
        file << "age,type,origin,rarity\n"; for (const Item& item : items) {
            file << item.age << "," << item.type << "," << item.origin << "," << item.rarityScore << "\n";
        } file.close();
    } else {std::cerr << "Error: Unable to open file " << filename << std::endl;} 
}