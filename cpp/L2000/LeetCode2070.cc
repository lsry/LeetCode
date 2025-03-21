#include <algorithm>
#include <vector>
using std::vector;

class Solution {
    int getBeautyValue(vector<vector<int>> const &items, int query) {
        int low{0}, high = items.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (items[mid][0] <= query) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low - 1 < 0 ? 0 : items[low - 1][1];
    }
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        std::sort(items.begin(), items.end(), [](vector<int> const &a, vector<int> const &b) {
            return a[0] < b[0];
        });
        int value{0};
        for (vector<int> &item : items) {
            value = std::max(item[1], value);
            item[1] = value;
        }
        vector<int> r;
        r.reserve(queries.size());
        for (int query : queries) {
            r.push_back(getBeautyValue(items, query));
        }
        return r;
    }
};