#include <string>
#include <algorithm>

class Solution {
public:
    int maximumSwap(int num) {
        if (num <= 11) {
            return num;
        }
        std::string ns = std::to_string(num);
        std::string ts{ns};
        std::stable_sort(ts.rbegin(), ts.rend());
        auto fn = ns.begin();
        auto ft = ts.begin();
        while (fn != ns.end() && *fn == *ft) {
            ++fn;
            ++ft;
        }
        if (fn == ns.end()) {
            return num;
        }
        auto sn{ns.end() - 1};
        while (sn != fn && *sn != *ft) {
            --sn;
        }
        auto c{*fn};
        *fn = *sn;
        *sn = c;
        return std::stoi(ns);
    }
};