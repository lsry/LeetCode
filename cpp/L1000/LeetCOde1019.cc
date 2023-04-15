#include "heads/list_node.h"
#include <vector>
using std::vector;
#include <stack>

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        std::stack<std::pair<int, int>> st;
        int id{0};
        for (ListNode *cur{head};cur != nullptr;cur = cur->next, ++id) {
            while (!st.empty() && st.top().second < cur->val) {
                res[st.top().first] = cur->val;
                st.pop();
            }
            st.emplace(std::pair<int, int>(id, cur->val));
            res.push_back(0);
        }
        return res;
    }
};