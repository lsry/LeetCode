class Solution {
public:
    int findKthNumber(int n, int k) {
        return findKth(0, n, k + 1);
    }

    int findKth(int low, int high, int k) {
        if (k == 1) {
            return low;
        }
        int num = 1;
        int cross = 0;
        --k;
        for (low = low + 1;;) {
            if (low * 10 <= high) {
                int cross2 = cross + low * 10 + 1;
                if (cross2 > k) {
                    return findKth(0, low * 10 - 1, k - cross) + low;
                } else if (k == cross2) {
                    return low * 10;
                } else {
                    low = low * 10 + 1;
                    cross = cross2;
                }
            } else {
                int cross2 = cross + high - low + 1;
                if (cross2 == k) {
                    return high;
                } else if (cross2 > k) {
                    return findKth(0, high - low - 1, k - cross) + low;
                } else {
                    ++num;
                    low = num;
                    cross = cross2;
                }
            }
        }
        return low;

    }
};