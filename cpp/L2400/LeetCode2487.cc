#include "../heads/list_node.h"
#include <stack>

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        std::stack<ListNode*> st;
        for (ListNode *cur{head};cur != nullptr;) {
            ListNode *node{cur};
            cur = cur->next;
            while (!st.empty() && st.top()->val < node->val) {
                st.pop();
            }
            if (!st.empty()) {
                st.top()->next = node;
            }
            node->next = nullptr;
            st.push(node);
        }
        while (st.size() > 1) {
            st.pop();
        }
        return st.empty() ? nullptr : st.top();
    }
};