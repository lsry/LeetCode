#include <vector>
using std::vector;

#include <string>
using std::string;

#include <unordered_set>
using std::unordered_set;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> res;
        for (string const &email : emails) {
            std::size_t ez{email.size()};
            std::string newEmail;
            bool domain = false;
            for (std::size_t i{0};i < ez;++i) {
                if (!domain && email[i] == '.') {
                    continue;
                }
                if (email[i] == '+') {
                    while (i < ez && email[i] != '@') {
                        ++i;
                    }
                    --i;
                } else if (email[i] == '@') {
                   domain = true;
                   newEmail.push_back('@');
                } else {
                     newEmail.push_back(email[i]);
                }
            }
            res.emplace(newEmail);
        }
        return res.size();
    }
};