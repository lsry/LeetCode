#include <queue>
#include <vector>
using std::vector;

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int N = status.size();
        // 0: have, 1: keys
        vector<vector<int>> flags(N, vector<int>(2, 0));
        std::queue<int> q;
        for (int box : initialBoxes) {
            flags[box][0] = 1;
            if (flags[box][0] == 1 && (status[box] == 1 || flags[box][1] == 1)) {
                q.push(box);
            }
        }
        int candy{0};
        vector<bool> visited(N, false);
        while (!q.empty()) {
            int box{q.front()};
            q.pop();
            if (visited[box]) {
                continue;
            }
            visited[box] = true;
            candy += candies[box];
            for (int keyBox : keys[box]) {
                flags[keyBox][1] = 1;
                if (!visited[keyBox] && flags[keyBox][0] == 1 && (status[keyBox] == 1 || flags[keyBox][1] == 1)) {
                    q.push(keyBox);
                }
            }
            for (int havaBox : containedBoxes[box]) {
                flags[havaBox][0] = 1;
                if (!visited[havaBox] && flags[havaBox][0] == 1 && (status[havaBox] == 1 || flags[havaBox][1] == 1)) {
                    q.push(havaBox);
                }
            }
        }
        return candy;
    }
};