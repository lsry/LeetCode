#include <vector>
using std::vector;

#include <string>
using std::string;
#include <unordered_map>

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int RN = req_skills.size(), PN = people.size();
        std::unordered_map<string, int> map;
        for (int i = 0;i < RN;++i) {
            map[req_skills[i]] = i;
        }
        vector<int> pSkills(PN, 0);
        for (int i = 0;i < PN;++i) {
            int skill{0};
            for (string s : people[i]) {
                skill |= (1 << map[s]);
            }
            pSkills[i] = skill;
        }
        vector<vector<int>> dp(PN + 1, vector<int>(1 << RN, -1));
        for (int i = 0;i <= PN;++i) {
            dp[i][0] = 0;
        }
        for (int i = 1;i <= PN;++i) {
            int pskill{pSkills[i - 1]};
            for (int j{0};j < (1 << RN);++j) {
                if (dp[i][j] == -1) {
                    dp[i][j] = dp[i - 1][j];
                }
                if (dp[i][j] == -1) {
                    continue;
                }
                int as = j | pskill;
                if (as == j) {
                    continue;
                }
                if (dp[i][as] == -1) {
                    dp[i][as] = dp[i - 1][as];
                }
                if (dp[i][as] == -1) {
                    dp[i][as] = dp[i][j] + 1;
                } else {
                    dp[i][as] = std::min(dp[i][as], dp[i][j] + 1);
                }
            }
        }
        vector<int> res;
        for (int i = PN, j = (1 << RN) - 1;i > 0 && j >= 0 && dp[i][j] != -1;--i) {
            int s = -1;
            int pskill = pSkills[i - 1];
            for (int k = j - 1;k >= 0;--k) {
                if ((k | pskill) == j && dp[i][k] + 1 == dp[i][j]) {
                    s = k;
                }
            }
            if (s != -1) {
                res.push_back(i - 1);
                j = s;
            }
        }
        return res;
    }
};