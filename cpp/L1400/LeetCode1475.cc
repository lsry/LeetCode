#include <vector>
using std::vector;
#include <stack>

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        if (prices.empty()) {
            return {};
        }
        int pz = prices.size();
        vector<int> res(pz, 0);
        std::stack<int> st;
        for (int i = 0;i < pz;++i) {
            while (!st.empty() && prices[i] <= prices[st.top()]) {
                int vi = st.top();
                st.pop();
                res[vi] = prices[vi] - prices[i];
            }
            st.push(i);
        }
        while (!st.empty()) {
            int vi = st.top();
            st.pop();
            res[vi] = prices[vi];
        }
        return res;
    }
};