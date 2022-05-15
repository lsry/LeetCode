#include <string>
using std::string;

#include <vector>
using std::vector;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        if (strs.empty()) {
            return 0;
        }
        int cnt = 0;
        std::size_t vz{strs.size()};
        std::size_t sz{strs[0].size()};
        for (std::size_t col{0};col < sz;++col) {
            for (std::size_t row{1};row < vz;++row) {
                if (strs[row][col] < strs[row - 1][col]) {
                    ++cnt;
                    break;
                }
            }
        } 
        return cnt;
    }
};