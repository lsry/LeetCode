#include <stack>

/**
 * 單調棧
 * 每進入一個數，需要向前看有多少數字不大於它。
 * 但是當數字彈出時，如果不記錄彈出數字，則會丟失一些數字。
 * 解決是記錄數字的索引或者彈出數字數目。
 */
class StockSpanner {
private:
    std::stack<std::pair<int, int>> st;
public:
    StockSpanner() {}
    
    int next(int price) {
        int count = 1;
        while (!st.empty() && st.top().first <= price) {
            count += st.top().second;
            st.pop();
        }
        st.emplace(std::pair(price, count));
        return count;
    }
};
