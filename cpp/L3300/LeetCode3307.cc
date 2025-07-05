#include <vector>
using std::vector;

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        unsigned long long int len{1ULL};
        int ix{0};
        vector<int> opers;
        while (len < k) {
            opers.push_back(operations[ix]);
            ix++;
            len *= 2;
        }      
        unsigned long long int curLen{len}, k1 = static_cast<unsigned long long int>(k - 1);
        vector<unsigned long long int> ids;
        ids.push_back(k1);
        for (int i = 0;i < ix;++i) {
            if (k1 >= curLen / 2) {
                k1 = k1 - curLen / 2;  
            } 
            ids.push_back(k1);
            curLen /= 2;
        }
        char x{'a'};
        for (int i = ix - 1, j = 0;i >= 0;--i,++j) {
            if (ids[i] != ids[i + 1] && opers[j] == 1) {
                x = x == 'z' ? 'a' : x + 1;
            }
        }
        return x;
    }
};

int main() {
    Solution s;
    vector<int> op{0,1,0,1};
    s.kthCharacter(10, op);
}