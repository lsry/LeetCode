#include <vector>
using std::vector;
#include <string>
using std::string;

class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> r(word.size(), 0);
        unsigned long long int sum{0};
        for (int i = 0;i < word.size();++i) {
            sum = sum * 10 + (word[i] - '0');
            sum %= m;
            if (sum == 0) {
                r[i] = 1;
            }
        }
        return r;
    }
};