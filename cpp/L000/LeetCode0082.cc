#include "../heads/list_node.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        ListNode *dptr{&dummy};
        while (head != nullptr) {
            if (head->next != nullptr && head->val == head->next->val) {
                while (head->next != nullptr && head->val == head->next->val) {
                    head = head->next;
                }
                head = head->next;
            } else {
                dptr->next = head;
                head = head->next;
                dptr = dptr->next;
                dptr->next = nullptr;
            } 
        }
        return dummy.next;
    }
};