#include <iostream>
#include <vector>
#include <map>

struct Bid {
    int address;
    int amount;
    int value;
};

class Contract {
    private:
        std::map<int, Bid> bids;
        std::vector<int> ids;
        int counter;
    public:
        Contract () {counter = 0;}

        void newBid (int address, int amount, int value) {
            Bid bid = {address, amount, value};

            if (ids.size() == 0) {bids[counter] = bid; ids.push_back(counter); counter++; return;}
            if (bids[ids[0]].value >= value) {bids[counter] = bid; ids.insert(ids.begin(), counter); counter++; return;}
            if (bids[ids[ids.size()-1]].value <= value) {bids[counter] = bid; ids.push_back(counter); counter++; return;}

            int head = 0; int tail = counter; int index; while (head <= tail) {
                int mid = (head + tail) / 2;

                if (bids[ids[mid]].value > value) {tail = mid;}
                else if (bids[ids[mid + 1]].value < value) {head = mid + 1;}
                else {index = mid + 1; break;}
            }

            while (bids[ids[index-1]].value == value && index > 0) {index--;} // to preserve cronological order
            
            bids[counter] = bid;
            ids.insert(ids.begin() + index, counter);

            counter++;
        }

        void print () {
            for (int i : ids) {
                std::cout << bids[i].value << " ";
            } std::cout << std::endl;
        }

        bool isSorted () {
            for (int i = 0; i < ids.size() - 1; i++) {
                if (bids[ids[i]].value > bids[ids[i+1]].value) {return false;}
            } return true;
        }

        void randTest (int n) {
            for (int i = 0; i < n; i++) {
                int x = rand() % 100; newBid(53, 53, x);
                if (!isSorted()) {std::cerr << "Error" << std::endl; return;}
            } std::cout << "Success" << std::endl;
        }

        void inputTest () {
            while (true) {
                int x; std::cin >> x; if (x == -1) {break;} newBid(53, 53, x);
                if (!isSorted()) {std::cerr << "Error" << std::endl; return;}
            } std::cout << "Success" << std::endl;
        }
};

int main () {
    Contract contract; 
    
    for (int i = 0; i < 100; i++) {contract.randTest(100);}

    return 0;
}