#include <vector>
using std::vector;

#include <unordered_map>

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        std::unordered_map<int, int> map;
        int ans{0}, left{0};
        int fz = fruits.size();
        for (int right = 0;right < fz;++right) {
            map[fruits[right]] += 1;
            if (map.size() > 2) {
                while (left < right && map.size() > 2) {
                    map[fruits[left]] -= 1;
                    if (map[fruits[left]] <= 0) {
                        map.erase(fruits[left]);
                    }
                    ++left;
                }
            }
            ans = std::max(ans, right - left + 1);
        }
        return ans;
    }
};