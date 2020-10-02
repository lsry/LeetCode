package L500;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import util.TreeNode;

public class LeetCode0501 {
    Map<Integer,Integer> freq;
    int maxFreq;

    /**
     * 用 Map 记录每个数字出现的频率，取出现频率最大的元素
     * T(N) = O(N), S(N) = O(N)
     */
    public int[] findModeByFreq(TreeNode root) {
        freq = new HashMap<>();
        maxFreq = 0;
        search(root);
        List<Integer> res = new ArrayList<>(8);
        for (Map.Entry<Integer,Integer> entry : freq.entrySet()) {
            if (entry.getValue() == maxFreq) {
                res.add(entry.getKey());
            }
        }
        int[] resa = new int[res.size()];
        for (int i = 0;i < resa.length;++i) {
            resa[i] = res.get(i);
        }
        return resa;
    }

    public void search(TreeNode node) {
        if (node != null) {
            int num = freq.getOrDefault(node.val, 0) + 1;
            if (num > maxFreq) {
                maxFreq = num;
            }
            freq.put(node.val, num);
            search(node.left);
            search(node.right);
        }
    }

    /**
     * 考虑中序遍历，可得到排序过的数字，依次统计每个数字出现频率即可
     */

    private int lastValue = Integer.MIN_VALUE;
    private int lastFreq = 0;
    private int curFreq = 0;
    private List<Integer> res = new ArrayList<>();
    private void inOrder(TreeNode root) {
        if (root != null) {
            inOrder(root.left);
            if (root.val == lastValue) {
                curFreq++;
            } else if (curFreq == lastFreq) {
                res.add(lastValue);
                curFreq = 1;
                lastValue = root.val;
            } else if (curFreq > lastFreq) {
                res.clear();
                res.add(lastValue);
                lastFreq = curFreq;
                curFreq = 1;
                lastValue = root.val;
            } else {
                curFreq = 1;
                lastValue = root.val;
            }
            inOrder(root.right);
        }
    }
    public int[] findMode(TreeNode root) {
        if (root == null) {
            return new int[]{};
        }
        lastValue = root.val;
        inOrder(root);
        if (curFreq == lastFreq) {
            res.add(lastValue);
        } else if (curFreq > lastFreq) {
            res.clear();
            res.add(lastValue);
        }
        int[] resa = new int[res.size()];
        for (int i = 0;i < resa.length;++i) {
            resa[i] = res.get(i);
        }
        return resa;
    }
}