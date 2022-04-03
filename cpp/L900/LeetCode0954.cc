#include <vector>
using std::vector;

#include <unordered_map>
using std::unordered_map;

#include <algorithm>

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> counts;
        for (const int num : arr) {
            counts[num] = counts[num] + 1;
        }
        if (counts[0] % 2 != 0) {
            return false;
        }
        int sz = arr.size();
        int zeroIndex = -1;
        std::stable_sort(arr.begin(), arr.end());
        for (int i = 0;i < sz;++i) {
            if (arr[i] > 0) {
                zeroIndex = i;
                break;
            }
        }
        if (zeroIndex != -1) {
            for (int i = zeroIndex;i < sz;++i) {
                int num = arr[i];
                if (counts[num] == 0) {
                    continue;
                }
                if (counts[2 * num] == 0) {
                    return false;
                }
                counts[2 * num] -= 1;
                counts[num] -= 1;
            }
        }
        for (int i = zeroIndex == -1 ? sz - counts[0] - 1 : zeroIndex - counts[0] - 1;i >= 0;--i) {
            int num = arr[i];
            if (counts[num] == 0) {
                    continue;
                }
            if (counts[2 * num] == 0) {
                return false;
            }
            counts[2 * num] -= 1;
            counts[num] -= 1;
        }
        
        return true;
    }
};