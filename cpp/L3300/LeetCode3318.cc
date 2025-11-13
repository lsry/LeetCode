#include <algorithm>
#include <cstddef>
#include <unordered_map>
#include <utility>
#include <vector>
using std::vector;

class Solution {
    int xSum(std::unordered_map<int, int> const &countMap, int x) {
        vector<std::pair<int, int>> vp;
        for (auto const &[k, v] : countMap) {
            if (v > 0) {
                vp.push_back(std::pair<int, int>(k, v));
            }
        }
        std::sort(vp.begin(), vp.end(), [](std::pair<int, int> const &p1, std::pair<int, int> const &p2) {
            return p1.second == p2.second ? p1.first > p2.first : p1.second > p2.second;
        });
        int sum{0};
        for (int i = 0;i < x && i < vp.size();++i) {
            sum += vp[i].first * vp[i].second;
        }
        return sum;
    }
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        std::unordered_map<int, int> countMap;
        std::size_t nz{nums.size()};
        vector<int> ans;
        for (std::size_t left{0}, right{0};right < nz;++right) {
            countMap[nums[right]]++;
            if (right - left + 1 < k) {
                continue;
            }
            while (right - left + 1 > k) {
                countMap[nums[left]]--;
                ++left;
            }
            ans.push_back(xSum(countMap, x));
        }
        return ans;
    }
};
