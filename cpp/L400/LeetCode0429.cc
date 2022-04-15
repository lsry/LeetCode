#include <vector>
using std::vector;

#include <queue>
using std::queue;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        queue<Node*> level_queue;
        if (root != nullptr) {
            level_queue.push(root);
        }
        while (!level_queue.empty()) {
            int sz = level_queue.size();
            vector<int> level;
            for (int i = 0;i < sz;++i) {
                Node *cur = level_queue.front();
                level_queue.pop();
                level.push_back(cur->val);
                for (Node* child : cur->children) {
                    level_queue.push(child);
                }
            }
            res.push_back(level);
        }
        return res;
    }
};