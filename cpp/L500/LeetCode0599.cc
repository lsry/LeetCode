#include <vector>
using std::vector;

#include <string>
using std::string;

#include <unordered_map>
using std::unordered_map;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, std::size_t> map;
        std::size_t sz = list1.size();
        for (std::size_t i= 0;i < sz;++i) {
            map.emplace(std::make_pair(list1[i], i));
        }
        std::size_t sz2 = list2.size();
        int index_sum = sz + sz2 + 1;
        vector<string> res;
        for (std::size_t i = 0;i < sz2;++i) {
            if (map.find(list2[i]) != map.end()) {
                if (i + map[list2[i]] == index_sum) {
                    res.push_back(list2[i]);
                } else if (i + map[list2[i]] < index_sum) {
                    index_sum = i + map[list2[i]];
                    res.clear();
                    res.push_back(list2[i]);
                }
            }
        }
        return res;
    }
};