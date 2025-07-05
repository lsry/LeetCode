#include <string>
using std::string;

class Solution {
public:
    int possibleStringCount(string word) {
        int ans{1};
        int N = word.size();
        for (int i = 0;i < N;) {
            int j = i;
            while (j < N && word[j] == word[i]) {
                ++j;
            }
            ans += j - i - 1;
            i = j;
        }      
        return ans;
    }
};