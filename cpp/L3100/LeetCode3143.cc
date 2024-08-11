#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <set>
#include <vector>
using std::vector;
#include <string>
using std::string;

class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int N = points.size();
        vector<int> ids(N, 0);
        std::iota(ids.begin(), ids.end(), 0);
        std::sort(ids.begin(), ids.end(), [&](int a, int b){
            return std::max(std::abs(points[a][0]), std::abs(points[a][1])) 
                 < std::max(std::abs(points[b][0]), std::abs(points[b][1]));
        });
        std::set<char> st;
        int ans{0};
        for (int i = 0;i < N;) {
            bool flag{false};
            int j = i;
            int cnt{0};
            while (j < N && std::max(std::abs(points[ids[j]][0]), std::abs(points[ids[j]][1])) <= std::max(std::abs(points[ids[i]][0]), std::abs(points[ids[i]][1]))) {
                if (st.contains(s[ids[j]])) {
                    flag = true;
                    break;
                }
                st.emplace(s[ids[j]]);
                ++cnt;
                ++j;
            }
            if (flag) {
                break;
            }
            ans += cnt;
            i = j;
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> v{{16,32},{27,3},{23,-14},{-32,-16},{-3,26},{-14,33}};
    string str{"aaabfc"};
    Solution s;
    s.maxPointsInsideSquare(v, str);
}