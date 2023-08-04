#include "../heads/list_node.h"

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {
            return false;
        }
        for (ListNode *slow{head}, *fast{head->next};fast != slow;) {
            if (fast == nullptr || fast->next == nullptr || fast->next->next == nullptr) {
                return false;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        return true;
    }
};