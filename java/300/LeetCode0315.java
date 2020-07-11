import java.util.ArrayList;
import java.util.List;

public class LeetCode0315 {
    class Node {
        public int val;
        public int count; // 左子树结点数目
        public Node left;
        public Node right;

        public Node (int val) {
            this.val = val;
            this.count = 0;
        }
    }
    public Node insert(Node root, int val, int index, List<Integer> res) {
        if (root == null) {
            return new Node(val);
        }
        if (root.val > val) {
            root.count += 1;
            root.left = insert(root.left, val, index, res);
        } else {
            res.set(index, res.get(index) + root.count + 1);
            root.right = insert(root.right, val, index, res);
        }
        return root;
    }
    public List<Integer> countSmaller(int[] nums) {       
        if (nums == null || nums.length <= 0) {
            return new ArrayList<>();
        }
        List<Integer> res = new ArrayList<>(nums.length);
        Node root = null;
        for (int i = 0;i < nums.length;++i) {
            res.add(0);
        }
        for (int i = nums.length - 1;i >= 0;--i) {
            root = insert(root, nums[i], i, res);
        }
        return res;
    }
}