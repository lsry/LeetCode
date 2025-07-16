#include "../heads/list_node.h"

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans{0};
        for (ListNode *cur{head};cur != nullptr;cur = cur->next) {
            ans = ans * 2 + cur->val;
        }
        return ans;
    }
};