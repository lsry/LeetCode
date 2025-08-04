#include <vector>
using std::vector;

#include <unordered_map>

class Solution {
public:
    int totalFruitMap(vector<int>& fruits) {
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

    int totalFruit(vector<int>& fruits) {
        int ans{0};
        int first = -1, second = -1;
        int cur{0};
        for (int i = 0;i < fruits.size();++i) {
            if (first == -1) {
                ++cur;
                first = fruits[i];
            } else if (second == -1) {
                ++cur;
                second = fruits[i];
            } else if (fruits[i] == first || fruits[i] == second) {
                ++cur;
            } else {
                int j = i - 1;
                while (j >= 0 && fruits[i - 1] == fruits[j]) {
                    --j;
                }
                cur = i - 1 - j;
                i--;
                first = fruits[i];
                second = -1;
            }
            ans = std::max(ans, cur);
        }
        return ans;
    }
};