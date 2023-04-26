#include <vector>
using std::vector;
#include <algorithm>
#include <string>
using std::string;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<int> vi(heights.size(), 0);
        for (std::size_t i{0};i < heights.size();++i) {
            vi[i] = i;
        }
        std::stable_sort(vi.begin(), vi.end(), [&](int a , int b) {
            return heights[a] >= heights[b];
        });
        vector<string> res(heights.size(), "");
        std::transform(vi.begin(), vi.end(), res.begin(), [&](int x) {
            return names[x];
        });
        return res;
    }
};