#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        std::sort(players.begin(), players.end());
        std::sort(trainers.begin(), trainers.end());
        int ans{0};
        for (auto pt{players.cbegin()}, tt{trainers.cbegin()};pt != players.cend() && tt != trainers.cend();++pt) {
            while (tt != trainers.cend() && *tt < *pt) {
                ++tt;
            }
            if (tt == trainers.cend()) {
                break;
            }
            ++ans;
            ++tt;
        }      
        return ans;
    }
};