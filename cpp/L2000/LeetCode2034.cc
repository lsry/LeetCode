#include <map>

class StockPrice {
    int timestamp, price;
    std::map<int, int> timePrices, pricesCount;
public:
    StockPrice(): timestamp(0), price(0) {}
    
    void update(int timestamp, int price) {
        if (timestamp >= this->timestamp) {
            this->timestamp = timestamp;
            this->price = price;
        }
        auto it{timePrices.find(timestamp)};
        if (it != timePrices.end()) {
            pricesCount[it->second] -= 1;
            if (pricesCount[it->second] <= 0) {
                pricesCount.erase(it->second);
            }
            it->second = price;
            pricesCount[price] += 1;
        } else {
            timePrices[timestamp] = price;
            pricesCount[price] += 1;
        }
    }
    
    int current() {
        return this->price;
    }
    
    int maximum() {
        return pricesCount.rbegin()->first;
    }
    
    int minimum() {
        return pricesCount.cbegin()->first;
    }
};