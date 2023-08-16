#include "../heads/list_node.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        ListNode *node{&dummy};
        while (head != nullptr) {
            ListNode *next{head->next};
            if (head->next != nullptr) {
                next = head->next->next;
                node->next = head->next;
                node->next->next = head;
                head->next = nullptr;
            } else {
                node->next = head;
            }
            node = head;
            head = next;
        }
        return dummy.next;
    }
};