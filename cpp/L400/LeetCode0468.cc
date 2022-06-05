#include <string>
using std::string;

class Solution {
private:
    string validIPV4(string &ip) {
        int seg = 1;
        std::size_t ipz{ip.size()};
        for (std::size_t i{0};i < ipz;) {
            if (ip[i] == '.') {
                ++seg;
                ++i;
            }
            if (ip[i] == '0' && !(i + 1 == ipz || ip[i + 1] == '.')) {
                return "Neither";
            }
            int num = 0;
            int segLen = 0;
            while (i < ipz && ip[i] != '.') {
                ++segLen;
                if (num > 255) {
                    return "Neither";
                }
                if (ip[i] >= '0' && ip[i] <= '9') {
                    num = (int)(num * 10) + (ip[i] - '0');
                } else {
                    return "Neither";
                }
                ++i;
            }
            if (num > 255 || segLen == 0 || segLen > 3) {
                return "Neither";
            }
        }

        return seg == 4 ? "IPv4" : "Neither";
    }
    string validIPV6(string &ip) {
        int seg = 1;
        std::size_t ipz{ip.size()};
        for (std::size_t i{0};i < ipz;) {
            if (ip[i] == ':') {
                ++seg;
                ++i;
            }
            int segLen = 0;
            while (i < ipz && ip[i] != ':') {
                ++segLen;
                if ((ip[i] >= '0' && ip[i] <= '9') || (ip[i] >= 'A' && ip[i] <= 'F') || (ip[i] >= 'a' && ip[i] <= 'f')) {
                    ++i;
                } else {
                    return "Neither";
                }
            }
            if (segLen > 4 || segLen < 1) {
                return "Neither";
            }
        }
        return seg == 8 ? "IPv6" : "Neither";
    }
public:
    string validIPAddress(string queryIP) {
        int pos = -1;
        for (std::size_t i{0};i < queryIP.size();++i) {
            if (queryIP[i] == '.') {
                pos = 4;
            } else if (queryIP[i] == ':') {
                pos = 6;
            }
        }
        if (pos == 4) {
            return validIPV4(queryIP);
        } else if (pos == 6) {
            return validIPV6(queryIP);
        } else {
            return "Neither";
        }
    }
};