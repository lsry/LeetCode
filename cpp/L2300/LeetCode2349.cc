#include <set>
#include <unordered_map>
class NumberContainers {
    std::unordered_map<int, int> idxMap;
    std::unordered_map<int, std::set<int>> numMap;
public:
    NumberContainers() {}
    
    void change(int index, int number) {
        auto iter{idxMap.find(index)};
        if (iter == idxMap.end()) {
            idxMap[index] = number;
            numMap[number].insert(index);
        } else {
            int old = iter->second;
            iter->second = number;
            numMap[old].erase(index);
            numMap[number].insert(index);
        }
    }
    
    int find(int number) {
       auto iter = numMap.find(number);
       if (iter == numMap.end() || iter->second.empty()) {
            return -1;
       } else {
            return *(iter->second.begin());
       }
    }
};