package L100;

import java.util.ArrayList;
import java.util.List;

import util.ListNode;
import util.TreeNode;

public class LeetCode0109 {
    public TreeNode sortedListToBST(ListNode head) {
        List<ListNode> nodes = new ArrayList<>();
        ListNode ni = head;
        while (ni != null) {
            nodes.add(ni);
            ni = ni.next;
        }
        return constructTree(nodes, 0, nodes.size() - 1);
    }

    private TreeNode constructTree(List<ListNode> nodes, int left, int right) {
        if (left < 0 || left > right || right >= nodes.size()) {
            return null;
        }
        int mid = (left + right) / 2;
        TreeNode cur = new TreeNode(nodes.get(mid).val);
        cur.left = constructTree(nodes, left, mid - 1);
        cur.right = constructTree(nodes, mid + 1, right);
        return cur;
    }
}