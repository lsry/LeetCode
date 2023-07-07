#include <iostream>
using namespace std;
#include "heads/list_node.h"

int getLength(ListNode *l)
{
    int i = 0;
    ListNode *p = l;
    while (p != NULL)
    {
        i++;
        p = p->next;
    }
    return i;
}
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *p = NULL, *q = NULL;
    int len1 = getLength(l1);
    int len2 = getLength(l2);
    len1 >= len2 ? (p = l1, q = l2) : (p = l2, q = l1);
    int m = 0;
    while (p != NULL && q != NULL)
    {
        int temp = (p->val + q->val + m) % 10;
        m = (p->val + q->val + m) / 10;
        p->val = temp;
        if (p->next == NULL && m > 0)
        {
            ListNode *node = new ListNode(m);
            p->next = node;
        }
        p = p->next;
        q = q->next;
    }
    while (m != 0 && len1 != len2)
    {
        int k = (p->val + m) % 10;
        m = (p->val + m) / 10;
        p->val = k;
        if (p->next == NULL && m > 0)
        {
            ListNode *node = new ListNode(m);
            p->next = node;
            m = 0;
        }
        p = p->next;
    }
    if (len1 >= len2)
    {
        return l1;
    }

    else
        return l2;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        int carry{0};
        ListNode *hp = &head;
        for (;l1 != nullptr || l2 != nullptr;) {
            if (l1 == nullptr) {
                carry += l2->val;
                l2 = l2->next;
            } else if (l2 == nullptr) {
                carry += l1->val;
                l1 = l1->next;
            } else {
                carry = carry + l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
            }
            hp->next = new ListNode(carry % 10);
            carry /= 10;
            hp = hp->next;
        }
        while (carry != 0) {
            hp->next = new ListNode(carry % 10);
            carry /= 10;
            hp = hp->next;
        }
        return head.next;
    }
};