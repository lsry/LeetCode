#include <stack>

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
