#include <string>
class Solution {
public:
    int maxDiff(int num) {
        std::string ms{std::to_string(num)};
        int ix{0};
        while (ix < ms.size() && ms[ix] == '9') {
            ++ix;
        }  
        int maxValue{0};    
        if (ix < ms.size()) {
            char c = ms[ix];
            for (int i = ix;i < ms.size();++i) {
                if (ms[i] == c) {
                    ms[i] = '9';
                }
            }
        }
        maxValue = std::stoi(ms);
        ix = 0;
        std::string ns{std::to_string(num)};
        while (ix < ns.size() && (ns[ix] == '1' || ns[ix] == '0')) {
            ++ix;
        }
        int minValue{0};
        if (ix < ns.size()) {
            char c = ns[ix];
            for (int i = ix;i < ns.size();++i) {
                if (ns[i] == c) {
                    ns[i] = ix > 0 ? '0' : '1';
                }
            }
        }
        minValue = std::stoi(ns);
        return maxValue - minValue;
    }
};