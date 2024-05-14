#include <vector>
using std::vector;

class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int ans{0};
        int  alice{capacityA}, bob{capacityB};
        for (int low{0}, high = plants.size() - 1;low <= high;++low, --high) {
            if (low < high) {
                if (alice < plants[low]) {
                    ++ans;
                    alice = capacityA;
                }
                alice -= plants[low];
                if (bob < plants[high]) {
                    ++ans;
                    bob = capacityB;
                }
                bob -= plants[high];
            } else if (alice >= bob) {
                if (alice < plants[low]) {
                    ++ans;
                    alice = capacityA;
                }
                alice -= plants[low];
            } else {
                if (bob  < plants[high]) {
                    ++ans;
                    bob = capacityB;
                }
                bob -= plants[high];
            }
        }
        return ans;
    }
};