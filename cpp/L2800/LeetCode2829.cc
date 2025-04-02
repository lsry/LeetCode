#include <unordered_set>
class Solution {
public:
    int minimumSum(int n, int k) {
        std::unordered_set<int> st;
        int sum{0};
        for (int i = 0, num = 1;i < n;++i, ++num) {
            while (st.contains(num)) {
                ++num;
            }
            sum += num;
            if (k - num >= 1) {
                st.emplace(k - num);
            }
        }        
        return sum;
    }   
};