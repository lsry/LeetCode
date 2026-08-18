#include <unordered_map>
#include <vector>
using std::vector;

class Solution {
    constexpr static int S6789{0b11110};
    constexpr static int S4567{0b1111000};
    constexpr static int S2345{0b111100000};
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        std::unordered_map<int, int> seats;
        for (vector<int> const &reservedSeat : reservedSeats) {
            auto it = seats.find(reservedSeat[0] - 1);
            if (it == seats.end()) {
                int x = 1 << (10 - reservedSeat[1]);
                seats[reservedSeat[0] - 1] = x;
            } else {
                it->second = (it->second) | (1 << (10 - reservedSeat[1]));
            }
        }
        int ans{2 * (n - static_cast<int>(seats.size()))};
        for (auto const &[r, s] : seats) {
            bool v1 = (S6789 & s) == 0;
            bool v2 = (S2345 & s) == 0;
            bool v3 = (S4567 & s) == 0;
            if (v1 && v2) {
                ans += 2;
            } else if (v1 || v2 || v3) {
                ans += 1;
            }
        }
        return ans;
    }
};
