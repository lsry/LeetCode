#include <iostream>
#include <string>
#include <vector>
using std::string;

class Solution {
    std::vector<unsigned long long int> splitVersion(string const &version) {
        std::vector<unsigned long long int> vs;
        int N = version.size();
        for (int i = 0;i < N;) {
            if (version[i] == '.') {
                ++i;
                continue;
            }
            unsigned long long int s{0ULL};
            int j{i};
            while (j < N && version[j] != '.') {
                s = s * 10 + (version[j] - '0');
                ++j;
            }
            vs.push_back(s);
            i = j;
        }
        return vs;
    }
public:
    int compareVersion(string version1, string version2) {
        std::vector<unsigned long long int> vs1{splitVersion(version1)};
        std::vector<unsigned long long int> vs2{splitVersion(version2)};
        for (int one = 0, two = 0;one < vs1.size() || two < vs2.size();++one, ++two) {
            unsigned long long int s1 = 0;
            if (one < vs1.size()) {
                s1 = vs1[one];
            }
            unsigned long long int s2 = 0;
            if (two < vs2.size()) {
                s2 = vs2[two];
            }
            if (s1 != s2) {
                return s1 < s2 ? -1 : 1;
            }
        }
        return 0;
    }
};

int main() {
    Solution s;
    string s1{"19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0000.0.0.0.0"};
    string s2{"19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000"};
    int x = s.compareVersion(s1, s2);
    std::cout << x;
}