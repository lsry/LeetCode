#include <limits>
#include <vector>
using std::vector;
#include "../heads/list_node.h"

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans{std::numeric_limits<int>::max(), -1};
        int lastIndex{-1};
        int firstIndex{-1};
        int endIndex{-1};
        int index{0};
        for (ListNode *prev{nullptr}, *cur{head};cur != nullptr && cur->next != nullptr;cur = cur->next) {
            if (prev != nullptr && ((prev->val < cur->val && cur->val > cur->next->val)
                || (prev->val > cur->val && cur->val < cur->next->val))) {
                    if (lastIndex != -1) {
                        ans[0] = std::min(index - lastIndex, ans[0]);
                    }
                    if (firstIndex == -1) {
                        firstIndex = index;
                    }
                    endIndex = index;
                    lastIndex = index;
            }
            ++index;
            prev = cur;
        }
        ans[0] = ans[0] == std::numeric_limits<int>::max() ? -1 : ans[0];
        ans[1] = firstIndex == -1 || endIndex == -1  || endIndex == firstIndex ? -1 : endIndex - firstIndex;
        return ans;
    }
};
