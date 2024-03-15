#include <array>
#include <string>
using std::string;

class Solution {
public:
    string getHint(string secret, string guess) {
        int matched{0}, nums{0};
        std::array<int, 10> counts{0};
        for (int i = 0;i < secret.size();++i) {
            if (secret[i] == guess[i]) {
                ++matched;
            } else {
                counts[guess[i] - '0'] += 1;
            }
        }
        for (int i = 0;i < secret.size();++i) {
            if (secret[i] != guess[i]) {
                if (counts[secret[i] - '0'] > 0) {
                    ++nums;
                    counts[secret[i] - '0'] -= 1;
                }
            }
        }
        return std::to_string(matched) + "A" + std::to_string(nums) + "B";
    }
};