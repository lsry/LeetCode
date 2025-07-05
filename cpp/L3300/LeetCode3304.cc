#include <string>
using std::string;

class Solution {
public:
    char kthCharacter(int k) {
        string s{"a"};
        while (s.size() < k) {
            int N = s.size();
            for (int i = 0;i < N;++i) {
                char c = s[i] == 'z' ? 'a' : static_cast<char>(s[i] + 1);
                s.push_back(c);
            }
        }      
        return s[k - 1];
    }
};