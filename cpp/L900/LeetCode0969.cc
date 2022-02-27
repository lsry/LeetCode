#include <vector>
using std::vector;

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n * 2);
        for (int i = n;i > 1;--i) {
            int id = find(arr, i);
            if (id != i - 1) {
                res.push_back(id + 1);
                reverse(arr, 0, id);
                res.push_back(i);
                reverse(arr, 0, i - 1);
            }
        }
        return res;
    }

private:
    int find(vector<int> &arr, int t) {
        int sz = arr.size();
        for (int i = 0;i < sz;++i) {
            if (arr[i] == t) {
                return i;
            }
        }
        return 0;
    }

    void reverse(vector<int> &arr, int l, int r) {
        while (l < r) {
            int t = arr[l];
            arr[l] = arr[r];
            arr[r] = t;
            ++l;
            --r;
        }
    }
};