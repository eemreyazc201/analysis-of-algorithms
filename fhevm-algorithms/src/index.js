class Bid {
    constructor(address, amount, value) {
        this.address = address;
        this.amount = amount;
        this.value = value;
    }
}

class Contract {
    constructor() {
        this.bids = new Map(); // Stores bids with counter as key
        this.ids = []; // Sorted array of bid keys (counter values)
        this.counter = 0; // Counter for unique bid IDs
    }

    newBid(address, amount, value) {
        const bid = new Bid(address, amount, value);

        if (this.ids.length === 0) {
            this.bids.set(this.counter, bid);
            this.ids.push(this.counter);
            this.counter++;
            return;
        }

        if (this.bids.get(this.ids[0]).value >= value) {
            this.bids.set(this.counter, bid);
            this.ids.unshift(this.counter);
            this.counter++;
            return;
        }

        if (this.bids.get(this.ids[this.ids.length - 1]).value <= value) {
            this.bids.set(this.counter, bid);
            this.ids.push(this.counter);
            this.counter++;
            return;
        }

        let head = 0, tail = this.ids.length - 1, index; while (head <= tail) {
            const mid = Math.floor((head + tail) / 2);

            if (this.bids.get(this.ids[mid]).value > value) {tail = mid;} 
            else if (this.bids.get(this.ids[mid + 1]).value < value) {head = mid + 1;} 
            else {index = mid + 1; break;}
        }

        while (this.bids.get(this.ids[index - 1]).value === value && index > 0) {index--;}

        this.bids.set(this.counter, bid);
        this.ids.splice(index, 0, this.counter);
        this.counter++;
    }

    print() {
        console.log(this.ids.map(id => this.bids.get(id).value).join(' '));
    }

    isSorted() {
        for (let i = 0; i < this.ids.length - 1; i++) {
            if (this.bids.get(this.ids[i]).value > this.bids.get(this.ids[i + 1]).value) {return false;}
        }
        return true;
    }

    randTest(n) {
        for (let i = 0; i < n; i++) {
            const x = Math.floor(Math.random() * 100); this.newBid(53, 53, x);
            if (!this.isSorted()) {console.error("Error"); return;}
        } console.log("Success");
    }
}

const contract = new Contract();

for (let i = 0; i < 100; i++) {
    contract.randTest(100);
}