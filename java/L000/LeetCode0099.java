package L000;

import java.util.ArrayList;
import java.util.List;

import util.TreeNode;

public class LeetCode0099{

    /**
     * 考虑中序遍历结果，会破坏递增序列
     * 存在 A[i] > A[i + 1], A[y] > A[y + 1]
     * 对应结点 A[i], A[y + 1]
     */
    public void recoverTree(TreeNode root) {
        List<TreeNode> miTree = new ArrayList<>();
        inorder(root, miTree);
        int x = -1, y = -1;
        int i = 0;
        for (;i < miTree.size() - 1;++i) {
            if (miTree.get(i).val > miTree.get(i + 1).val) {
                x = i;
                y = i + 1;
                break;
            }
        }
        for (i = i + 1;i < miTree.size() - 1;++i) {
            if (miTree.get(i).val > miTree.get(i + 1).val) {
                y = i + 1;
                break;
            }
        }
        if (x != -1) {
            int val = miTree.get(x).val;
            miTree.get(x).val = miTree.get(y).val;
            miTree.get(y).val = val;
        }
    } 

    private void inorder(TreeNode root,List<TreeNode> miTree) {
        if (root == null) {
            return;
        }
        inorder(root.left, miTree);
        miTree.add(root);
        inorder(root.right, miTree);
    }
}