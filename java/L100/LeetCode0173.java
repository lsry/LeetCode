package L100;

import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedList;
import java.util.List;

import util.TreeNode;

public class LeetCode0173 {}

/**
 * 迭代中序遍历的过程
 * 用栈临时存储未访问过的根及右子树
 */
class BSTIteratorInOrderProcess {
    Deque<TreeNode> stack = new LinkedList<>();

    public BSTIteratorInOrderProcess(TreeNode root) {
        TreeNode t = root;
        while (t != null) {
            stack.addFirst(t);
            t = t.left;
        }        
    }
    
    /** @return the next smallest number */
    public int next() {
        TreeNode cur = stack.removeFirst();
        int v = cur.val;
        TreeNode rchild = cur.right;
        while (rchild != null) {
            stack.addFirst(rchild);
            rchild = rchild.left;
        }
        return v;
    }
    
    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        return !stack.isEmpty();
    }
}

/**
 * 先使用中序遍历，将结果存到数组中，然后再迭代
 */
class BSTIterator {
    private List<Integer> nums;
    private int index;

    public BSTIterator(TreeNode root) {
        Deque<TreeNode> stack = new LinkedList<>();
        nums = new ArrayList<>();
        while (!stack.isEmpty() || root != null) {
            while (root != null) {
                stack.addFirst(root);
                root = root.left;
            }
            root = stack.removeFirst();
            nums.add(root.val);
            root = root.right;
        }
        index = 0;
    }
    
    public int next() {
        ++index;
        return nums.get(index - 1);
    }
    
    public boolean hasNext() {
        return index < nums.size();
    }
}
