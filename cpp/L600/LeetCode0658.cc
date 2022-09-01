#include <vector>
using std::vector;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int az = arr.size();
        int j{0}, right{az - 1};
        while (j <= right) {
            int mid = (j + right) / 2;
            if (arr[mid] == x) {
                j = mid;
                break;
            } else if (arr[mid] < x) {
                j = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        j = std::max(0, std::min(j, az - 1));
        while (j - 1 >= 0 && arr[j - 1] == x) {
            --j;
        }
        if (j >= 0 && arr[j] != x) {
            j = std::max(0, j - 1);
        }
        int i = std::max(j - k + 1, 0);
        int count = j - i + 1;
        for (j = j + 1;j < az;++j) {
            if (count < k) {
                ++count;
                continue;
            }
            if (arr[j] - x >= x - arr[i]) {
                break;
            } else {
                ++i;
            }
        }
        vector<int> res;
        while (i < az && i < j) {
            res.push_back(arr[i]);
            ++i;
        }
        return res;
    }
};