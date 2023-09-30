package L700;

public class LeetCode0786 {
    private static class Node {
        public int x, y;
        public Node(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public int[] kthSmallestPrimeFraction(int[] arr, int k) {
        Node[] nodes = divide(arr, k, 1, arr.length - 1);
        return new int[] {nodes[k - 1].x, nodes[k - 1].y};
    }

    private Node[] divide(int[] arr, int k, int start, int end) {
        if (start == end) {
            int len = Math.min(start, k);
            Node[] res = new Node[len];
            for (int i = 0;i < len;++i) {
                res[i] = new Node(arr[i], arr[start]);
            }
            return res;
        }
        int mid = (start + end) / 2;
        Node[] left = divide(arr, k, start, mid);
        Node[] right = divide(arr, k, mid + 1, end);
        return merge(left, right, k);
    }

    private Node[] merge(Node[] left, Node[] right, int k) {
        int i = 0, j = 0;
        int len = Math.min(left.length + right.length, k);
        Node[] res = new Node[len];
        int idx = 0;
        while (idx < len && (i < left.length || j < right.length)) {
            if (i == left.length) {
                res[idx++] = right[j++];
            } else if (j == right.length) {
                res[idx++] = left[i++];
            } else {
                if (left[i].x * right[j].y < right[j].x * left[i].y) {
                    res[idx++] = left[i++];
                } else {
                    res[idx++] = right[j++];
                }
            }
        }
        return res;
    }

    public static void main(String[] args) {
        LeetCode0786 lc = new LeetCode0786();
        int[] arr = new int[] {1, 2, 3, 5};
        int k = 3;
        lc.kthSmallestPrimeFraction(arr, k);
    }
}