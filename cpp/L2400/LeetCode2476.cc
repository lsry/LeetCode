#include "../heads/tree_node.h"
#include <limits>
#include <vector>
using std::vector;

class Solution {
    void inorder(TreeNode *node, vector<int> &arr) {
        if (node != nullptr) {
            inorder(node->left, arr);
            arr.push_back(node->val);
            inorder(node->right, arr);
        }
    }
    int findLessOrEqual(vector<int> const &arr, int v) {
        int t = -1;
        for (int low = 0, high = arr.size() - 1;low <= high;) {
            int mid = (low + high) / 2;
            if (arr[mid] <= v) {
                t = std::max(arr[mid], t);
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return t;
    }
    int findMoreOrEqual(vector<int> &arr, int v) {
        int t = std::numeric_limits<int>::max();
        for (int low = 0, high = arr.size() - 1;low <= high;) {
            int mid{(low + high) / 2};
            if (arr[mid] >= v) {
                t = std::min(t, arr[mid]);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return t == std::numeric_limits<int>::max() ? -1 : t;
    }
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> res;
        if (root == nullptr || queries.empty()) {
            return res;
        }
        res.reserve(queries.size());
        vector<int> arr;
        inorder(root, arr);
        for (int query : queries) {
            vector<int> r{0, 0};
            r[0] = findLessOrEqual(arr, query);
            r[1] = findMoreOrEqual(arr, query);
            res.emplace_back(r);
        }
        return res;
    }
};