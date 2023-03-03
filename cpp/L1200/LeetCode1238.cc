#include <vector>
using std::vector;
#include <string>

class Solution {
    int parse(std::string &s) {
        int x{0};
        for (auto it = s.rbegin();it != s.rend();++it) {
            x = x * 2 + (*it == '1' ? 1 : 0);
        }
        return x;
    }

    void reverse(vector<int> &nums, int start, int end) {
        while (start < end) {
            int t = nums[start];
            nums[start] = nums[end];
            nums[end] = t;
            ++start;
            --end;
        }
    }
public:
    vector<int> circularPermutation(int n, int start) {
        int N = 1 << n;
        vector<int> res(N, 0);
        int si = 0;
        std::string num(n, '0');
        for (int i = 1;i < N;++i) {
            num[n - 1] = num[n - 1] == '0' ? '1' : '0';
            res[i] = parse(num);
            if (res[i] == start) {
                si = i;
            }
            ++i;
            int j = n - 1;
            while (j > 0 && num[j] == '0') {
                --j;
            }
            if (j <= 0) {
                break;
            }
            --j;
            num[j] = (num[j] == '0') ? '1' : '0';
            res[i] = parse(num);
            if (res[i] == start) {
                si = i;
            }
        }
        reverse(res, 0, si - 1);
        reverse(res, si, N - 1);
        reverse(res, 0, N - 1);
        return res;
    }
};