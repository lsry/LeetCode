#include <vector>
using std::vector;

#include <unordered_set>

#include "heads/list_node.h"

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        std::unordered_set<int> set;
        for (int num : nums) {
            set.insert(num);
        }
        int count{0};
        for (ListNode *node{head};node != nullptr;) {
            if (set.find(node->val) != set.end()) {
                while (node != nullptr && set.find(node->val) != set.end()) {
                    node = node->next;
                }
                ++count;
            } else {
                node = node->next;
            }
        }
        return count;
    }
};