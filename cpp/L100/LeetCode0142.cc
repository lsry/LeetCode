#include "../heads/list_node.h"

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow{head}, *fast{head};
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                break;
            }
        }
        if (fast == nullptr || fast->next == nullptr) {
            return nullptr;
        }
        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};