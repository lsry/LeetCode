#include <array>
#include <string>
#include <unordered_map>
using std::string;

class Solution {
    std::unordered_map<char, int> mp;
    
    bool check(std::array<int, 6> const &counts, int k) {
        if (counts[0] < k) {
            return false;
        }
        for (int i = 1;i < 6;++i) {
            if (counts[i] == 0) {
                return false;
            }
        }
        return true;
    }

    long long int atLeastK(string const &word, int k) {
        long long int ans{0};
        std::array<int, 6> counts{0};
        int N = word.size();
        for (int low{0}, high{0};low < N;++low) {
            while(high < N && !check(counts, k)) {
                int id = mp[word[high]];
                counts[id]++;
                ++high;
            }
            if (check(counts, k)) {
                ans += N - high + 1;
            }
            int id = mp[word[low]];
            --counts[id];
        }
        return ans;
    }
public:
    Solution() {
        mp['a'] = 1;
        mp['e'] = 2;
        mp['i'] = 3;
        mp['o'] = 4;
        mp['u'] = 5;
    }
    long long countOfSubstrings(string word, int k) {
        return atLeastK(word, k) - atLeastK(word, k + 1);
    }
};