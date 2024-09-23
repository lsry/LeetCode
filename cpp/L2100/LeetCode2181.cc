#include "../heads/list_node.h"

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode dummy;
        ListNode *pointer = &dummy;
        while (head != nullptr) {
            if (head->val == 0) {
                head = head->next;
            } else {
                int val{0};
                while (head != nullptr && head->val != 0) {
                    val += head->val;
                    head = head->next;
                }
                ListNode* cur = new ListNode(val);
                pointer->next = cur;
                pointer = cur;
            }
        }
        return dummy.next;
    }
};