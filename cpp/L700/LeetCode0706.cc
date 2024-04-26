#include <vector>
class MyHashMap {
    constexpr static int N{1000100};
    std::vector<int> maps;
public:
    MyHashMap(): maps(N, -1) {}
    
    void put(int key, int value) {
        maps[key] = value;
    }
    
    int get(int key) {
        return maps[key];
    }
    
    void remove(int key) {
        maps[key] = -1;
    }
};