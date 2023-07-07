#include "heads/list_node.h"

class Solution {
    ListNode* reverseList(ListNode *head) {
        ListNode dummy(0);
        for (ListNode *cur{head};cur != nullptr;) {
            ListNode *next = cur->next;
            cur->next = dummy.next;
            dummy.next = cur;
            cur = next;
        }
        return dummy.next;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *r1 = reverseList(l1);
        ListNode *r2 = reverseList(l2);
        ListNode dummy(0);
        int carry{0};
        while (r1 != nullptr || r2 != nullptr) {
            if (r2 == nullptr) {
                carry += r1->val;
                r1 = r1->next;
            } else if (r1 == nullptr) {
                carry += r2->val;
                r2 = r2->next;
            } else {
                carry += r1->val + r2->val;
                r1 = r1->next;
                r2 = r2->next;
            }
            ListNode* cur = new ListNode(carry % 10);
            cur->next = dummy.next;
            dummy.next = cur;
            carry /= 10;
        }
        while (carry != 0) {
            ListNode* cur = new ListNode(carry % 10);
            cur->next = dummy.next;
            dummy.next = cur;
            carry /= 10;
        }
        return dummy.next;
    }
};