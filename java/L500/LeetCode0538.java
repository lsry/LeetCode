package L500;

import util.TreeNode;

public class LeetCode0538 {
    /**
     * 后中序遍历，右 -> 根 -> 左
     * 需要记录前次遍历节点值，然后加起来
     */
    public TreeNode convertBST(TreeNode root) {
        convert(0, root);
        return root;
    }

    public int convert(int max,TreeNode node){
        int x = max;
        if (node != null){
            if (node.right != null){
                x = convert(x, node.right);
            } 
            node.val += x;
            x = node.val;
            if (node.left != null){
                x = convert(x, node.left);
            }
        }
        return x;
    }
}