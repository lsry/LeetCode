package L800;

import java.util.ArrayDeque;
import java.util.Deque;

import util.TreeNode;

public class LeetCode0897 {
    // 构造新结点
    public TreeNode increasingBSTNewNode(TreeNode root) {
        TreeNode head = new TreeNode(0);
        TreeNode h = head;
        Deque<TreeNode> stack = new ArrayDeque<>();
        TreeNode cur = root;
        while (cur != null || !stack.isEmpty()){
            while (cur != null){
                stack.addFirst(cur);
                cur = cur.left;
            }
            cur = stack.removeFirst();
            h.right = new TreeNode(cur.val); // 如果不重新生成一棵树，需要将左孩子设置为null,否则不再为一棵树
                                             // 形成环，在遍历树的过程中形成死循环
            h = h.right;
            cur = cur.right;
        }
        return head.right;
    }

    /**
     * 重构树中结点
     */
    public TreeNode increasingBST(TreeNode root) {
        TreeNode head = new TreeNode(0);
        TreeNode right = head;
        Deque<TreeNode> stack = new LinkedList<>();
        while (root != null || !stack.isEmpty()) {
            while (root != null) {
                stack.addFirst(root);
                root = root.left;
            }
            root = stack.removeFirst();
            right.right = root;
            root.left = null;
            root = root.right;
            right = right.right;
        }
        return head.right;
    }
}