#include <vector>
using std::vector;

class Solution {
public:
    /**
     * 考慮當前數組 A 和已排序成功的數組 B，從左到右遍歷兩個數組，對應索引 i，j，可能有以下情況：
     * 1）A[i] > B[j]：表示 A[i0..i] 無法和 B[j0..j] 對應，將 j 移動到 B[j] = A[i] 的位置；   
     * 2）A[i] < B[j] && i < j：表示 A[i] 處在 B[j0...j] 的範圍内；
     * 3）i == j：表示 A[i0..i] 和 B[j0..j] 對應，此時分成一塊；    
     */
    int maxChunksToSorted(vector<int>& arr) {
        int az = arr.size();
        int ans = 0;
        int mv = 0;
        for (int i = 0;i < az;++i) {
            mv = std::max(mv, arr[i]);
            if (i == mv) {
                ++ans;
            }
        }
        return ans;
    }
};