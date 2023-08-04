#include "../heads/list_node.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode head(0);
        ListNode *tail{&head};
        while (list1 != nullptr || list2 != nullptr) {
            if (list1 == nullptr) {
                tail->next = list2;
                list2 = list2->next;
            } else if (list2 == nullptr) {
                tail->next = list1;
                list1 = list1->next;
            } else if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        return head.next;
    }
};