#include <unordered_map>
using std::unordered_map;

#include <vector>
using std::vector;

#include <random>

class RandomizedSet {
private:
    unordered_map<int, int> map;
    vector<int> vi;
    int idx;
public:
    RandomizedSet() : idx(-1), vi(300000) {}
    
    bool insert(int val) {
        if (map.find(val) != map.end()) {
            return false;
        }
        ++idx;
        vi[idx] = val;
        map[val] = idx;
        return true;
    }
    
    bool remove(int val) {
        if (map.find(val) == map.end()) {
            return false;
        }
        if (idx == 0) {
            idx = -1;
            map.clear();
            return true;
        }
        int id = map[val];
        int lval = vi[idx];
        map[lval] = id;
        vi[id] = lval;
        map.erase(val);
        --idx;
        return true;
    }
    
    int getRandom() {
        static std::default_random_engine random_engine;
        std::uniform_int_distribution<std::size_t> dis(0, idx);
        std::size_t id = dis(random_engine);
        return vi[id];
    }
};