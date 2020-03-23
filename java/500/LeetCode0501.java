import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class LeetCode0501 {
    Map<Integer,Integer> freq;
    int maxFreq;

    /**
     * T(N) = O(N), S(N) = O(N)
     */
    public int[] findMode(TreeNode root) {
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
}