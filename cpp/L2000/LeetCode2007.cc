#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int N = changed.size();
        if (N % 2 != 0) {
            return {};
        }
        vector<int> ori, two;
        int index{0};
        std::sort(changed.begin(), changed.end());
        for (int num : changed) {
            if (num % 2 != 0 || index >= ori.size() || 2 * ori[index] != num) {
                ori.push_back(num);
            } else {
                two.push_back(num);
                ++index;
            }
        }
        return ori.size() == N / 2 ? ori : vector<int>{};
    }
};