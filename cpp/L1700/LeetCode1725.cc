#include <vector>
using std::vector;

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int len = 0, count = 0;
        for (vector<int> &rect : rectangles) {
            int e = std::min(rect[0], rect[1]);
            if (e == len) {
                count++;
            } else if (e > len) {
                len = e;
                count = 1;
            }
        }        
        return count;
    }
};