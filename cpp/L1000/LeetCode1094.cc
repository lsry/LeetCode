#include <vector>
using std::vector;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> customers(1002, 0);
        for (vector<int> const &trip : trips) {
            customers[trip[1]] += trip[0];
            customers[trip[2]] -= trip[0];
        }
        int count{0};
        for (int customer : customers) {
            count += customer;
            if (count > capacity) {
                return false;
            }
        }
        return true;
    }
};