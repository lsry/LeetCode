#include <vector>
using std::vector;
#include <unordered_map>

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        std::unordered_map<int, vector<int>> map;
        std::size_t az{arr.size()}, p{0};
        for (vector<int> &piece : pieces) {
            map[piece[0]] = piece;
            p += piece.size();
        }
        if (p != az) {
            return false;
        }
        for (std::size_t i{0};i < az;) {
            if (map.find(arr[i]) == map.end()) {
                return false;
            }
            vector<int> &piece = map[arr[i]];
            for (std::size_t j{0};j < piece.size() && i < az;++j, ++i) {
                if (arr[i] != piece[j]) {
                    return false;
                }
            }
        }
        return true;
    }
};