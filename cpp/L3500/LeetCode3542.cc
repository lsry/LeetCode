#include <stack>
#include <vector>
using std::vector;

class Solution {
public:
    int minOperations(vector<int>& nums) {
       int ans{0};
       std::stack<int> st;
       for (int num : nums) {
          while (!st.empty() && st.top() > num) {
              st.pop();
          }
          if (num == 0) {
              continue;
          }
          if (st.empty() || st.top() < num) {
              ++ans;
              st.push(num);
          }
       }
       return ans;
    }
};
