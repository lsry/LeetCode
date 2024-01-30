#include <string>
#include <algorithm>

class Solution {
public:
    int maximumSwap2(int num) {
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

    int maximumSwap(int num) {
        if (num <= 11) {
            return num;
        }
        std::string ns = std::to_string(num);
        int nz = ns.size();
        for (int i = 0;i < nz;++i) {
            if (changeLetter(ns, i)) {
                break;
            }
        }
        return std::stoi(ns);
    }

    bool changeLetter(std::string &ns, int id) {
        int eid = id;
        for (int i = id + 1;i < ns.size();++i) {
            if (ns[i] >= ns[eid]) {
                eid = i;
            }
        }
        if (eid != id && ns[eid] != ns[id]) {
            std::swap(ns[eid], ns[id]);
            return true;
        }
        return false;
    }
};