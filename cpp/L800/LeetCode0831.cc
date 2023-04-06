#include <string>
using std::string;
#include <cctype>
#include <algorithm>

class Solution {
    string maskEmail(string const &email) {
        string res;
        std::size_t ez{email.size()};
        std::size_t id{0};
        std::size_t ei{0};
        while (email[id] != '@') {
            ++id;
        }
        ei = id - 1;
        res.push_back(email[0]);
        res.append("*****");
        res.push_back(email[ei]);
        res.append(email.substr(id, ez - id));
        string r(res.size(), '0');
        std::transform(res.begin(), res.end(), r.begin(), ::tolower);
        return r;
    }
    string maskPhone(string const &phone) {
        string r;
        for (char c : phone) {
            if (std::isdigit(c)) {
                r.push_back(c);
            }
        }
        int type = r.size() - 10;
        string res{"**"};
        if (type > 0) {
            res[0] = '+';
        } 
        switch (type)
        {
        case 0:
            res.append("*-***-");
            break;
        case 1:
            res.append("-***-***-");
            break;
        case 2:
            res.append("*-***-***-");
            break;
        default:
            res.append("**-***-***-");
        }
        res.append(r.substr(r.size() - 4, 4));
        return res;
    }
public:
    string maskPII(string s) {
        return std::isalpha(s[0]) ? maskEmail(s) : maskPhone(s);
    }
};