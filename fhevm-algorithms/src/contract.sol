// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract Contract {
    struct Bid {
        address bidder;
        uint256 amount;
        uint256 value;
    }

    mapping(uint256 => Bid) private bids; // Maps counter to Bid
    uint256[] private ids; // Sorted array of bid IDs
    uint256 private counter; // Counter for unique bid IDs

    constructor() {counter = 0;}

    function newBid(address bidder, uint256 amount, uint256 value) public {
        Bid memory bid = Bid(bidder, amount, value);

        if (ids.length == 0) {
            bids[counter] = bid;
            ids.push(counter);
            counter++;
            return;
        }

        if (bids[ids[0]].value >= value) {
            bids[counter] = bid;
            ids.push(0); for (uint256 i = ids.length - 1; i > 0; i--) {ids[i] = ids[i - 1];} ids[0] = counter;
            counter++;
            return;
        }

        if (bids[ids[ids.length - 1]].value <= value) {
            bids[counter] = bid;
            ids.push(counter);
            counter++;
            return;
        }

        uint256 head = 0; uint256 tail = ids.length - 1; uint256 index; while (head <= tail) {
            uint256 mid = (head + tail) / 2;

            if (bids[ids[mid]].value > value) {tail = mid;}
            else if (bids[ids[mid + 1]].value < value) {head = mid + 1;} 
            else {index = mid + 1; break;}
        }

        while (bids[ids[index - 1]].value == value && index > 0) {index--;}

        bids[counter] = bid;
        
        ids.push(0); for (uint256 i = ids.length - 1; i > index; i--) {ids[i] = ids[i - 1];} ids[index] = counter;

        counter++;
    }
}
