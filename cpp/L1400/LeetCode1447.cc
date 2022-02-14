#include <vector>
using std::vector;
#include <string>
using std::string;

class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> vs(n);
        for (int i = 2;i <= n;++i) {
            for (int j = 1;j < i;++j) {
                if (gcd(i, j) == 1) {
                    string s = std::to_string(j) + "/" + std::to_string(i);
                    vs.push_back(s);
                }
            }
        }
        return vs;
    }
private:
    int gcd(int a, int b) {
        while (b != 0) {
            int c = a - b;
            a = c > b ? c : b;
            b = c > b ? b : c;
        }
        return a;
    }
};