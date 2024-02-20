#include <vector>
using std::vector;

#include <stack>
using std::stack;

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

/**
 * 將孩子逆序加入棧中
 */
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        stack<Node*> st;
        st.push(root);
        while (!st.empty()) {
            Node* cur = st.top();
            st.pop();
            res.push_back(cur->val);
            for (int i = cur->children.size() - 1;i >= 0;--i) {
                st.push(cur->children[i]);
            }
        }
        return res;
    }
};