#include "../heads/list_node.h"

class Solution {
    ListNode* reverse(ListNode *head) {
        ListNode dummy(0);
        while (head != nullptr) {
            ListNode *next = head->next;
            head->next = dummy.next;
            dummy.next = head;
            head = next;
        }
        return dummy.next;
    }
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        ListNode *slow{head}, *fast{head->next->next};
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *rList = reverse(slow->next);
        slow->next = nullptr;
        slow = head;
        while (rList != nullptr) {
            ListNode *next = rList->next;
            rList->next = slow->next;
            slow->next = rList;
            rList = next;
            if (slow->next->next != nullptr) { // 偶数情况
                slow = slow->next->next;
            } else { // 奇数情况：逆序链表多了一个数
                slow = slow->next;
            }
        }
    }
};