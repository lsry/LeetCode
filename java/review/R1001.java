package review;

public class R1001 {
    public void merge(int[] A, int m, int[] B, int n) {
        int a = 0, b = 0;
        int ai = m;
        while (a < ai && b < n) {
            if (A[a] <= B[b]) {
                ++a;
            } else {
                int bb = b;
                for (;bb < n && B[bb] < A[a];++bb);
                for (int aa = ai - 1;aa >= a;--aa) {
                    A[aa + bb - b] = A[aa];
                }
                ai = ai + bb - b;
                for (int i = b;i < bb;++i) {
                    A[a] = B[i];
                    ++a;
                }
                b = bb;   
            }
        }
        if (b < n) {
            for (;b < n;++b) {
                A[a] = B[b];
                ++a;
            }
        }
    }
}