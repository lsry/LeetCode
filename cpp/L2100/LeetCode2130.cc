#include "../heads/list_node.h"
#include <vector>

class Solution {
public:
    int pairSum(ListNode* head) {
        std::vector<int> v;
        while (head != nullptr) {
            v.push_back(head->val);
            head = head->next;
        }
        int N =v.size();
        int ans{0};
        for (int l = 0, r = N - 1;l < r;++l, --r) {
            ans = std::max(ans, v[l] + v[r]);
        }
        return ans;
    }
};
