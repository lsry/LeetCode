#include <vector>
using std::vector;
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> sorted(arr);
        std::stable_sort(sorted.begin(), sorted.end());
        std::unordered_map<int, int> map;
        std::size_t az{arr.size()};
        int ans{0}, dif{0};
        for (std::size_t i{0};i < az;++i) {
            int a = arr[i];
            map[a]++;
            if (map[a] == 0) {
                dif -= 1;
            } else if (map[a] == 1) {
                dif += 1;
            }
            a = sorted[i];
            map[a]--;
            if (map[a] == 0) {
                dif -= 1;
            } else if (map[a] == -1) {
                dif += 1;
            }
            if (dif == 0) {
                ++ans;
            }
        }
        return ans;
    }
};