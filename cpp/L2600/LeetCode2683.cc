#include <vector>
using std::vector;

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int value{0};
        int cur{value};
        for (int d : derived) {
            if (d == 1) {
                cur = 1 - cur;
            }
        } 
        if (cur == value) {
            return true;
        }     
        value = 1;
        cur = value;
        for (int d : derived) {
            if (d == 1) {
                cur = 1 - cur;
            }
        }
        return cur == value;
    }
};