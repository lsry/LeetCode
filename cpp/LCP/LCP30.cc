#include <functional>
#include <queue>
#include <vector>
using std::vector;

class Solution {
public:
// error
    int magicTower(vector<int>& nums) {
        int adjustCount{0};
        std::priority_queue<int, vector<int>, std::greater<int>> pq;
        long long int monsters{0LL};
        long long int bleed{1};
        for (int num : nums) {
            if (num >= 0) {
                bleed += num;
            } else if (bleed + num > 0) {
                bleed += num;
                pq.push(num);
            } else {
                while (!pq.empty() && bleed + num <= 0) {
                    bleed -= pq.top();
                    monsters += pq.top();
                    pq.pop();
                    ++adjustCount;
                }
                if (bleed + num > 0) {
                    bleed += num;
                    pq.push(num);
                } else {
                   monsters += num;
                   ++adjustCount;
                }
                
            }
        }
        return bleed + monsters > 0 ? adjustCount : -1;
    }
};

int main() {
    Solution s;
    vector<int> rooms{-200,-300,400,0};
    s.magicTower(rooms);
}