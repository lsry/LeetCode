#include <vector>
using std::vector;
#include <algorithm>

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> arr{a, b, c};
        std::sort(arr.begin(), arr.end());
        vector<int> res(2, 0);
        res[1] = arr[2] - arr[0] + 1 - 3;
        if (arr[1] == arr[0] + 2 || arr[2] == arr[1] + 2) {
            res[0] = 1;
        } else {
            if (arr[1] > arr[0] + 1) {
                res[0] += 1;
            }
            if (arr[2] > arr[1] + 1) {
                res[0] += 1;
            }
        }
        return res;
    }
};