#include <vector>
using std::vector;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int N = nums.size();
        vector<int> counts(N, 1);
        for (int i = 1;i < N;++i) {
            if (nums[i] % 2 != nums[i - 1] % 2) {
                counts[i] += counts[i - 1];
            }
        }
        int QN = queries.size();
        vector<bool> answers(QN, false);
        for (int i = 0;i < QN;++i) {
            if (counts[queries[i][1]] >= queries[i][1] - queries[i][0] + 1) {
                answers[i] = true;
            }
        }
        return answers;
    }
};