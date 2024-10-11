#include <string>
using std::string;

class Solution {
public:
    int takeCharacters(string s, int k) {
        int na{0}, nb{0}, nc{0};
        for (char const c : s) {
            if (c == 'a') {
                na++;
            } else if (c == 'b') {
                nb++;
            } else {
                ++nc;
            }
        }      
        if (na < k || nb < k || nc < k) {
            return -1;
        }
        if (k == 0) {
            return 0;
        }
        int ans = s.size(), N = s.size();
        int a = 0, b = 0, c = 0;
        for (int low{-1}, high = N;low < N;++low) {
            if (low >= 0) {
                if (s[low] == 'a') {
                    ++a;
                } else if (s[low] == 'b') {
                    ++b;
                } else {
                    ++c;
                }
            }
            do {
                if (high >= N) {
                    break;
                }
                if (s[high] == 'a' && a > k) {
                    --a;
                } else if (s[high] == 'b' && b > k) {
                    --b;
                } else if (s[high] == 'c' && c > k) {
                    --c;
                } else {
                    break;
                }
                ++high;
            } while (true);
            while (a < k || b < k || c < k && high > low + 1) {
                --high;
                if (s[high] == 'a') {
                    ++a;
                } else if (s[high] == 'b') {
                    ++b;
                } else {
                    ++c;
                }
            }
            if (a >= k && b >= k && c >= k) {
                ans = std::min(ans, low + 1 + N - high);
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    s.takeCharacters("cbbac", 1);
}