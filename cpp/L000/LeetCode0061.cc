#include "../heads/list_node.h"

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode fisrt(0);
        fisrt.next = head;
        ListNode *tail = &fisrt;
        int len = 0;
        while (tail->next != nullptr) {
            ++len;
            tail = tail->next;
        }
        ListNode *hp = &fisrt;
        k = k % len;
        for (int i = 0;i < len - k;++i) {
            hp = hp->next;
        }
        tail->next = head;
        ListNode *n = hp->next;
        hp->next = nullptr;
        return n;
    }
};
