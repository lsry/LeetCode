#include <array>
#include <limits>
#include <string>
using std::string;

class Solution {
    int getStatus(int x, int y) {
        return ((x & 1) << 1) | (y & 1);
    }
public:
    int maxDifference(string s, int k) {
        int ans{std::numeric_limits<int>::min()};
        int N = s.size();
        int intMax = std::numeric_limits<int>::max();
        for (char a = '0';a < '5';++a) {
            for (char b = '0';b < '5';++b) {
                if (a == b) {
                    continue;
                }
                std::array<int, 4> counts{intMax, intMax, intMax, intMax};
                int ca{0}, cb{0};
                int pa{0}, pb{0};
                for (int left{-1}, right{0};right < N;++right) {
                    ca += (s[right] == a ? 1 : 0);
                    cb += (s[right] == b ? 1 : 0);
                    while (right - left >= k && cb - pb >= 2) {
                        int bs = getStatus(pa, pb);
                        counts[bs] = std::min(counts[bs], pa - pb);
                        ++left;
                        pa += (s[left] == a ? 1 : 0);
                        pb += (s[left] == b ? 1 : 0);
                    }
                    int as = getStatus(ca, cb);
                    if (counts[as ^ 0b10] != intMax) {
                        ans = std::max(ans, ca - cb - counts[as ^ 0b10]);
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    s.maxDifference("12233", 4);
}