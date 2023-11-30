#include <unordered_set>

class SmallestInfiniteSet {
    std::unordered_set<int> st;
    int minVal;
public:
    SmallestInfiniteSet(): minVal(1) {}
    
    int popSmallest() {
        while (st.find(minVal) != st.end()) {
            ++minVal;
        }
        int t{minVal};
        st.insert(t);
        ++minVal;
        return t;
    }
    
    void addBack(int num) {
        st.erase(num);
        if (num >= minVal) {
            return;
        }
        minVal = num;
    }
};