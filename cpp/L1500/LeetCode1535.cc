#include <vector>
using std::vector;

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int N = arr.size();
        for (int i = 0;i < N;) {
            int j = i + 1;
            while (j < N && arr[j] < arr[i]) {
                ++j;
            }
            int turn = i > 0 ? j - i : j - i - 1;
            if (turn >= k || j == N) {
                return arr[i];
            }
            i = j;
        }
        return arr[0];
    }
};