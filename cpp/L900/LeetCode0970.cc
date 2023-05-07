#include <vector>
using std::vector;
#include <set>

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> xs;
        if (x != 1) {
            for (int i{1};i <= bound;i *= x) {
                xs.push_back(i);
            }
        } else {
            xs.push_back(1);
        }
        vector<int> ys;
        if (y != 1) {
            for (int i {1};i <= bound;i *= y) {
                ys.push_back(i);
            }
        } else {
            ys.push_back(1);
        }
        std::set<int> st;
        for (int i{0};i < xs.size() && xs[i] < bound;++i) {
            for (int j{0};j < ys.size() && xs[i] + ys[j] <= bound;++j) {
                st.emplace(xs[i] + ys[j]);
            }
        }
        return {st.begin(), st.end()};
    }
};