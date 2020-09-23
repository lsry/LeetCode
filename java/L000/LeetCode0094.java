package L000;

import java.util.*;

import util.TreeNode;

public class LeetCode0094{
    /**
     * 使用栈存储下一步访问的结点
     */
    public List<Integer> inorderTraversalIter(TreeNode root) {
        List<Integer> li = new ArrayList<>();
        Stack<TreeNode> stn = new Stack<>();
        TreeNode tn = root;
        while (tn != null || !stn.empty()){
            while (tn != null){
                stn.push(tn);
                tn = tn.left;
            }
            tn = stn.pop();
            li.add(tn.val);
            tn = tn.right;
        }
        return li;
    }

    /**
     * 递归
     */
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        inorderRecur(root, res);
        return res;
    }

    private void inorderRecur(TreeNode root,List<Integer> res) {
        if (root != null) {
            inorderRecur(root.left, res);   
            res.add(root.val);
            inorderRecur(root.right, res);
        }
    }
}