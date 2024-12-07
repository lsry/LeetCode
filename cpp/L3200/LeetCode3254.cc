#include <vector>
using std::vector;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> res;
        int N = nums.size();
        for (int i = 0, j = 0;j < N;++j) {
            if (j - i + 1 == k) {
                if (k == 1 || nums[j] - 1 == nums[j - 1]) {
                    res.push_back(nums[j]);
                    ++i;
                } else {
                    while (i < j && N - i >= k) {
                        res.push_back(-1);
                        ++i;
                    }
                    j = i - 1;
                }
            } else if (j > i && nums[j] - 1 != nums[j - 1]) {
                while (i < j && N - i >= k) {
                    res.push_back(-1);
                    ++i;
                }
                j = i - 1;
            }
            if (N - i < k) {
                break;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> x{1,3,4};
    s.resultsArray(x, 2);
}