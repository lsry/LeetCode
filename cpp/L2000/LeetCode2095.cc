#include "../heads/list_node.h"

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode node(0);
        node.next = head;
        ListNode *fast = &node, *slow = &node;
        while (fast != nullptr && fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return node.next;
    }
};
