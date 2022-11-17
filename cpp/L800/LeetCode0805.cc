#include <vector>
using std::vector;
#include <unordered_set>
#include <algorithm>
#include <numeric>

class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return false;
        }
        int s = std::accumulate(nums.begin(), nums.end(), 0);
        std::transform(nums.begin(), nums.end(), nums.begin(), [s = s, n = n](int x) {return n * x - s;});
        int ln{n / 2};
        std::unordered_set<int> ls;
        for (int i{1};i < (1 << ln);++i) {
            int p{i};
            int sum{0};
            for (int j{0};j < ln && p != 0;++j) {
                if ((p & 1) == 1) {
                    sum += nums[j];
                }
                p = p >> 1;
            }
            if (sum == 0) {
                return true;
            }
            ls.insert(sum);
        }
        int rn{n - ln};
        int rsum{std::accumulate(nums.begin() + ln, nums.end(), 0)};
        for (int i{1};i < (1 << rn);++i) {
            int p{i};
            int sum{0};
            for (int j{0};j < rn && p != 0;++j) {
                if ((p & 1) == 1) {
                    sum += nums[ln + j];
                }
                p = p >> 1;
            }
            if (sum == 0 || rsum != sum && ls.find(-sum) != ls.end()) {
                return true;
            }
        }
        return false;
    }
};
