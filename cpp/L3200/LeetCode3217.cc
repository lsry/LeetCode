#include "../heads/list_node.h"
#include <unordered_set>
#include <vector>
using std::vector;

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        std::unordered_set<int> st;
        for (int num : nums) {
            st.insert(num);
        }
        ListNode h(0);
        h.next = head;
        ListNode *cur = &h;
        while (cur->next != nullptr) {
            ListNode *next = cur->next;
            if (st.contains(next->val)) {
                cur->next = next->next;
                next->next = nullptr;
            } else {
                cur = cur->next;
            }
        }
        return h.next;
    }
};
