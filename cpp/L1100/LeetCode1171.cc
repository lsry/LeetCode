#include "heads/list_node.h"

#include <vector>
#include <unordered_map>

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        std::unordered_map<int, int> map;
        std::vector<int> sums;
        sums.push_back(0);
        map[0] = 1;
        std::vector<ListNode*> nodes;
        for (ListNode *cur{head};cur != nullptr;cur = cur->next) {
            int sum{sums.back() + cur->val};
            auto curIter{map.find(sum)};
            if (curIter == map.end() || curIter->second == 0) {
                nodes.push_back(cur);
                sums.push_back(sum);
                map[sum] += 1;
            } else {
                while (sums.back() != sum) {
                    int x = sums.back();
                    map[x] -= 1;
                    sums.pop_back();
                    nodes.pop_back();
                }
            }
        }
        ListNode *next = nullptr;
        while (!nodes.empty()) {
            ListNode *node = nodes.back();
            nodes.pop_back();
            node->next = next;
            next = node;
        }
        return next;
    }
};