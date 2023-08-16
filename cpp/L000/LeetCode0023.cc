#include "../heads/list_node.h"
#include <vector>
using std::vector;
#include <queue>

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto f{[](ListNode *n1, ListNode *n2) {
            return n1->val > n2->val;
        }};
        std::priority_queue<ListNode*, vector<ListNode*>, decltype(f)> pq(f);
        ListNode dummy(0);
        ListNode *head{&dummy};
        for (ListNode *list : lists) {
            if (list != nullptr) {
                pq.push(list);
            }
        }
        while (!pq.empty()) {
            ListNode *node{pq.top()};
            pq.pop();
            head->next = node;
            if (node->next != nullptr) {
                pq.push(node->next);
            }
            head = head->next;
            head->next = nullptr;
        }
        return dummy.next;
    }
};