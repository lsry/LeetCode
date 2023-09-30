#include <algorithm>
#include <iterator>
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int>> r1;
        std::copy_if(restaurants.begin(), restaurants.end(), std::back_inserter(r1), [&](vector<int> const &r) {
            if (veganFriendly == 1 && r[2] == 0) {
                return false;
            }
            return r[3] <= maxPrice && r[4] <= maxDistance;
        });
        std::sort(r1.begin(), r1.end(), [](const vector<int> &v1, vector<int> const &v2) {
            return v1[1] == v2[1] ? v1[0] > v2[0] : v1[1] > v2[1];
        });
        vector<int> r;
        std::transform(r1.begin(), r1.end(), std::back_inserter(r), [](vector<int> const &v) {
            return v[0];
        });
        return r;
    }
};

int main() {
    vector<vector<int>> v{{0, 1, 1, 3, 4}, {5,6,0,8,9}};
    Solution s;
    s.filterRestaurants(v, 1, 30, 100);
    return 0;
}