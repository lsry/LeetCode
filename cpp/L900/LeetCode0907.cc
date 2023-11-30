#include <vector>
using std::vector;

#include <stack>

/**
 * @brief 在求左右最小值時，由於重複數字存在，要麽在左邊，或右邊取等號，不可同時取等
 * 
 */
class Solution {
private:
    constexpr static unsigned long long int MOD = 1'000'000'007ULL;
public:
    int sumSubarrayMins(vector<int>& arr) {
        std::size_t az{arr.size()};
        std::stack<int> st;
        vector<int> rMin(az, 0);
        for (int i = az - 1;i >= 0;--i) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                rMin[i] = az;
            } else {
                rMin[i] = st.top();
            }
            st.push(i);
        } 
        vector<int> lMin(az, 0);
        while (!st.empty()) {
            st.pop();
        }
        for (int i = 0;i < az;++i) {
            while (!st.empty() && arr[st.top()] > arr[i]) {  
                st.pop();
            }
            if (st.empty()) {
                lMin[i] = -1;
            } else {
                lMin[i] = st.top();
            }
            st.push(i);
        }
        unsigned long long int sum{0ULL};
        for (int i = 0;i < az;++i) {
            sum = (sum + (unsigned long long int)(rMin[i] - i) * (i - lMin[i]) * arr[i]) % MOD;
        }
        return (int)sum;
    }
};
