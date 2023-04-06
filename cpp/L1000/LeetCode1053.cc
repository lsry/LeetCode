#include <vector>
using std::vector;

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int az = arr.size();
        for (int i = az - 2;i >= 0;--i) {
            if (arr[i] <= arr[i + 1]) {
                continue;
            }
            int t = i + 1;
            for (int j{i + 2};j < az;++j) {
                if (arr[j] < arr[i] && arr[j] > arr[t]) {
                    t = j;
                }
            }
            std::swap(arr[i], arr[t]);
            break;
        }   
        return arr;
    }
};