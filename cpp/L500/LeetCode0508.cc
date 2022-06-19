#include "heads/tree_node.h"

#include <vector>
using std::vector;

#include <unordered_map>
#include <algorithm>

class Solution {
private:
    int getSubTreeSum(TreeNode *root, std::unordered_map<int, int> &map, int &maxCount) {
        if (root == nullptr) {
            return 0;
        }
        int sum = root->val + getSubTreeSum(root->left, map, maxCount) + getSubTreeSum(root->right, map, maxCount);
        map[sum] += 1;
        if (map[sum] > maxCount) {
            maxCount = map[sum];
        }
        return sum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        std::unordered_map<int, int> map;
        int maxCount = 0;
        getSubTreeSum(root, map, maxCount);
        vector<int> res;
        for (auto &[key, value] : map) {
            if (value == maxCount) {
                res.push_back(key);
            }
        }
        return res;
    }
};