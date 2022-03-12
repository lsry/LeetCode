#include <vector>
using std::vector;

#include <stack>
using std::stack;

#include <tuple>
using std::tuple;

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
    vector<int> postorder(Node* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        stack<tuple<Node*, Node*, int>> st;
        Node *node = root;
        Node *parent = nullptr;
        int index = -1;
        while (!st.empty() || node != nullptr) {
            while (node != nullptr) {
                st.push({parent, node, index});
                int sz = node->children.size();
                if (node -> children.size() > 0) {
                    parent = node;
                    node = node->children[0];
                    index = 0;
                } else {
                    parent = node;
                    node = nullptr;
                    index = -1;
                }
            }
            if (!st.empty()) {
                tuple<Node*, Node*, int> t = st.top();
                st.pop();
                res.push_back(std::get<1>(t)->val);
                int i = std::get<2>(t);
                Node *p = std::get<0>(t);
                if (p != nullptr && i + 1 < p->children.size()) {
                    node = p->children[i + 1];
                    index = i + 1;
                    parent = p;
                }
            }
        }
        return res;
    }
};