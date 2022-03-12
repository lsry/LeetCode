#include <vector>
using std::vector;

#include <array>
using std::array;

#include <string>
using std::string;

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<array<int, 2>> sum;
        int strLen = s.size();
        for (int i = 0;i < strLen;++i) {
            if (s[i] != '|') {
                continue;
            }
            if (sum.empty()) {
                array<int, 2> arr;
                arr[0] = i;
                arr[1] = 0;
                sum.push_back(arr);
            } else {
                int vz = sum.size();
                array<int, 2> arr;
                arr[0] = i;
                arr[1] = i - sum[vz - 1][0] - 1 + sum[vz - 1][1];
                sum.push_back(arr);
            }
        }
        int qz = queries.size();
        int sz = sum.size();
        vector<int> res;
        for (const vector<int> &query : queries) {
            int left = binSearchLeft(sum, 0, sz - 1, query[0]);
            int right = binSearchRight(sum, 0, sz - 1, query[1]);
            if (left != -1 && right != -1 && left <= right) {
                res.push_back(right - left);
            } else {
                res.push_back(0);
            }
        }
        return res;
    }

private:
    int binSearchLeft(vector<array<int, 2>> &sum, int x, int y, int target) {
        int t = -1;
        while (x <= y) {
            int m = (x + y) / 2;
            if (sum[m][0] >= target) {
                y = m - 1;
                t = m;
            } else {
                x = m + 1;
            }
        }
        return t == -1 ? t : sum[t][1];
    }

    int binSearchRight(vector<array<int, 2>> &sum, int x, int y, int target) {
        int t = -1;
        while (x <= y) {
            int m = (x + y) / 2;
            if (sum[m][0] <= target) {
                x = m + 1;
                t = m;
            } else {
                y = m - 1;
            }
        }
        return t == -1 ? t : sum[t][1];
    }
};