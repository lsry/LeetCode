#include <algorithm>
#include <vector>
using std::vector;
#include <string>
using std::string;

class Solution {
    bool validChar(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_';
    }
    bool validId(string const &id) {
        if (id.empty()) {
            return false;
        }
        for (char c : id) {
            if (!validChar(c)) {
                return false;
            }
        }
        return true;
    }
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<int> validIndex;
        int N = code.size();
        for (int i = 0;i < N;++i) {
            if (!validId(code[i])) {
                continue;
            }
            if (businessLine[i] != "electronics" && businessLine[i] != "grocery"
                && businessLine[i] != "pharmacy" && businessLine[i] != "restaurant") {
                continue;
            }
            if (!isActive[i]) {
                continue;
            }
            validIndex.emplace_back(i);
        }
        std::sort(validIndex.begin(), validIndex.end(), [&](int x, int y) {
            if (businessLine[x] != businessLine[y]) {
                return businessLine[x] < businessLine[y];
            }
            return code[x] < code[y];
        });
        vector<string> res;
        for (int ix : validIndex) {
            res.emplace_back(code[ix]);
        }
        return res;
    }
};
