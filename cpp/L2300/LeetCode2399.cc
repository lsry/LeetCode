#include <string>
using std::string;
#include <vector>
using std::vector;

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> pos(26, -1);
        for (int i = 0;i < s.size();++i) {
            int id = s[i] - 'a';
            if (pos[id] == -1) {
                pos[id] = i;
            } else if (distance[id] != i - pos[id] - 1){
                return false;
            }
        }
        return true;
    }
};