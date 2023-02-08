#include "heads/list_node.h"

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *first{nullptr}, *second{nullptr};
        ListNode *head{list1};
        for (int i = 0;i <= b;++i, head = head->next) {
            if (i == a - 1) {
                first = head;
            } else if (i == b) {
                second = head;
            }
        }
        head = list2;
        while (head->next != nullptr) {
            head = head->next;
        }      
        first->next = list2;
        head->next = second->next;
        second->next = nullptr;
        return list1;
    }
};