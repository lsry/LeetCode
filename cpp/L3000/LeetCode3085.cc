#include <array>
#include <limits>
#include <string>
using std::string;

class Solution {
public:
    int minimumDeletions(string word, int k) {
        std::array<int, 26> freq{0};
        for (char c : word) {
            freq[c - 'a'] ++;
        }  
        int ans{std::numeric_limits<int>::max()};
        for (int i = 0;i < 26;++i) {
            if (freq[i] == 0) {
                continue;
            }
            int deleted{0};
            for (int j = 0;j < 26;++j) {
                if (freq[j] == 0 || j == i) {
                    continue;
                }
                if (freq[j] < freq[i]) {
                    deleted += freq[j];
                } else if (freq[j] > freq[i] && freq[j] - freq[i] > k) {
                    deleted += freq[j] - freq[i] - k;
                }
            }
            ans = std::min(ans, deleted);
        }    
        return ans;
    }
};

int main() {
    Solution s;
    s.minimumDeletions("dabdcbdcdcd", 2);
}