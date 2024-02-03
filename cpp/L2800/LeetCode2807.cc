#include "../heads/list_node.h"
#include <numeric>

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *cur{head};
        while (cur != nullptr && cur->next != nullptr) {
            int val{std::gcd(cur->val, cur->next->val)};
            ListNode *node = new ListNode(val);
            node->next = cur->next;
            cur->next = node;
            cur = cur->next->next;
        }
        return head;
    }
};