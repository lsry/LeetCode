#include <vector>
using std::vector;
#include <queue>

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> childs(n, vector<int>());
        for (int i = 0;i < n;++i) {
            if (manager[i] != -1) {
                childs[manager[i]].push_back(i);
            }
        }
        std::queue<std::pair<int, int>> q;
        q.push(std::make_pair(headID, 0));
        int time{0};
        while (!q.empty()) {
            auto [id, it] = q.front();
            q.pop();
            time = std::max(time, it);
            for (int child : childs[id]) {
                q.push(std::make_pair(child, it + informTime[id]));
            }
        }
        return time;
    }
};

int main(int argc, char const *argv[])
{
    Solution s; 
    vector<int> m{2,2,-1,2,2,2}, t{0,0,1,0,0,0};
    s.numOfMinutes(6, 2, m, t);
    return 0;
}
