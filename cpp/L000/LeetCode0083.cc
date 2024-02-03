#include "../heads/list_node.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *cur{head};
        while (cur != nullptr) {
            if (cur->next != nullptr && cur->next->val == cur->val) {
                ListNode *next{cur->next};
                cur->next = next->next;
                next->next = nullptr;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};