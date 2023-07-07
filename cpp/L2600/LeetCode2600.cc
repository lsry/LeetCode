class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int goal{0};
        if (k > 0) {
            if (numOnes >= k) {
                goal += k;
                k = 0;
            } else {
                goal += numOnes;
                k -= numOnes;
            }
        }
        if (k > 0) {
            k = numZeros >= k ? 0 : k - numZeros;
        }
        if (k > 0) {
            goal = numNegOnes >= k ? goal - k : goal - numNegOnes;
        }
        return goal;
    }
};