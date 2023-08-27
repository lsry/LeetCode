#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int distance{0};
        int n = seats.size();
        for (int left{-1}, right{0},i{0};i < n;++i) {
            if (right <= i) {
                right = i + 1;
                while (right < n && seats[right] == 0) {
                    ++right;
                }
            }
            if (seats[i] == 0) {
                if (left >= 0 && right < n) {
                    distance = std::max(distance, std::min(i - left, right - i));
                }else if (right < n) {
                    distance = std::max(distance, right - i);
                } else if (left >= 0) {
                    distance = std::max(distance, i - left);
                }
            } else if (seats[i] == 1) {
                left = i;
                right = i;
                while (right < n && seats[right] == 0) {
                    ++right;
                }
            }
        }
        return distance;
    }
};