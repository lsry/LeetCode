#include <cstddef>
#include <vector>
using std::vector;

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        std::size_t sz{skill.size()}, mz{mana.size()};
        vector<long long> times(sz, 0LL);
        for (std::size_t i{0};i < mz;++i) {
            long long start{times[0]};
            for (std::size_t j{0};j < sz;++j) {
                long long time = skill[j] * mana[i];
                start = std::max(start, times[j]) + time;
                times[j] = start;
            }
            for (int j = sz - 1;j > 0;--j) {
                times[j - 1] = times[j] - skill[j] * mana[i];
            }
        }
        return times.back();
    }
};

int main() {
    vector<int> skill{1,5,2,4};
    vector<int> mana{5,1,4,2};
    Solution s;
    s.minTime(skill, mana);
}