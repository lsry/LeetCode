package L100;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

import util.TreeNode;

public class LeetCode0113 {
    
    /**
     * BFS
     * 需要用Map记录父节点
     */
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> res = new ArrayList<>();
        if (root == null) {
            return res;
        }
        HashMap<TreeNode, TreeNode> parents = new HashMap<>();
        Queue<TreeNode> qnodes = new LinkedList<>();
        Queue<Integer> qvals = new LinkedList<>();
        parents.put(root, null);
        qnodes.offer(root);
        qvals.offer(sum);
        while (!qnodes.isEmpty()) {
            TreeNode node = qnodes.poll();
            int val = qvals.poll();
            if (node.left == null && node.right == null) {
                if (val - node.val == 0) {
                    res.add(getPath(node, parents));
                }
            }
            if (node.left != null) {
                parents.put(node.left, node);
                qnodes.offer(node.left);
                qvals.offer(val - node.val);
            }
            if (node.right != null) {
                parents.put(node.right, node);
                qnodes.offer(node.right);
                qvals.offer(val - node.val);
            }
        }
        return res;
    }

    private List<Integer> getPath(TreeNode node,HashMap<TreeNode,TreeNode> parents) {
        List<Integer> path = new ArrayList<>();
        while (node != null) {
            path.add(node.val);
            node = parents.get(node);
        }
        Collections.reverse(path);
        return path;
    }

    /**
     * dfs 记录路径和，当遍历到叶子结点，和等于目标值，则加入到结果集中
     */

    List<List<Integer>> result = new ArrayList<>();
    private int SUM;
    public List<List<Integer>> pathSumDFS(TreeNode root, int sum) {
        SUM = sum;
        List<Integer> temp = new ArrayList<>();
        helper(root, temp, 0);
        return result;
    }

    public void helper(TreeNode root,List<Integer> middle,int curSum) {
        if (root == null){
            return;
        }
        curSum += root.val;
        middle.add(root.val);
        if (root.left == null && root.right == null){
            if (curSum == SUM){
                result.add(new ArrayList<>(middle));
            }
        } 
        if (root.left != null){
            helper(root.left, middle, curSum);
        }  
        if (root.right != null){
            helper(root.right, middle, curSum);
        }
        middle.remove(middle.size()-1);
    }
}