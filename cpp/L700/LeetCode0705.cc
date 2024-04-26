#include <algorithm>
#include <array>

class MyHashSet {
    constexpr static int N{100010};
    std::array<bool, N> flags;
public:
    MyHashSet() {
        std::fill(flags.begin(), flags.end(), false);
    }
    
    void add(int key) {
        flags[key] = true;
    }
    
    void remove(int key) {
        flags[key] = false;
    }
    
    bool contains(int key) {
        return flags[key];
    }
};