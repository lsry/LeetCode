#include <vector>
using std::vector;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int mv{arr[arr.size() - 1]};
        arr[arr.size() - 1] = -1;
        for (auto it{arr.rbegin() + 1};it != arr.rend();++it) {
            int c = *it;
            *it = mv;
            mv = std::max(mv, c);
        }
        return arr;
    }
};