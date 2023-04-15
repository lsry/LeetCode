#include <vector>
using std::vector;

#include <unordered_map>

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        std::unordered_map<int, int> map;
        for (int n : nums) {
            if (n % 2 == 0) {
                map[n] += 1;
            }
        }      
        int num{-1}, count{0};
        for (auto &[key, value] : map) {
            if (value > count || (value == count && key < num)) {
                num = key;
                count = value;
            }
        }
        return num;
    }
};