#include <vector>
using std:: vector;

class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> row(m, 0);
        vector<int> col(n, 0);
        for (vector<int> &index : indices) {
            row[index[0]] += 1;
            col[index[1]] += 1;
        }
        int odd = 0, even = 0;
        for (int x : col) {
            if (x % 2 == 0) {
                even += 1;
            } else {
                ++odd;
            }
        }
        int ans = 0;
        for (int x : row) {
            if (x % 2 == 0) {
                ans += odd;
            } else {
                ans += even;
            }
        }
        return ans;
    }
};