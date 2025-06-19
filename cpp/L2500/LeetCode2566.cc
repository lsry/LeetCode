#include <string>
class Solution {
public:
    int minMaxDifference(int num) {
        std::string ns = std::to_string(num); 
        int i = 0;
        while (i < ns.size() && ns[i] == '9') {
            ++i;
        }
        char x;
        if (i < ns.size()) {
            x = ns[i];  
            for (;i < ns.size();++i) {
                if (ns[i] == x) {
                    ns[i] = '9';
                }
            }   
        }
        int maxv = std::stoi(ns);
        std::string vs = std::to_string(num);
        x = vs[0];
        for (i = 0;i < ns.size();++i) {
            if (vs[i] == x) {
                vs[i] = '0';
            }
        }
        int minv = std::stoi(vs);
        return maxv - minv;
    }
};