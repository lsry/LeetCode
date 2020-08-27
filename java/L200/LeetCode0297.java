package L200;

import java.util.LinkedList;
import java.util.Queue;
import util.TreeNode;

public class LeetCode0297{}

class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if (root == null) {
            return "";
        }
        StringBuilder sb = new StringBuilder();
        Queue<TreeNode> qu = new LinkedList<>();
        qu.offer(root);
        boolean nextNum = true;
        while (!qu.isEmpty() && nextNum) {
            nextNum = false;
            int n = qu.size();
            for (int i = 0;i < n;++i) {
                TreeNode cur = qu.poll();
                if (cur == null) {
                    sb.append("n,");
                    continue;
                }
                sb.append(cur.val);
                sb.append(',');
                if (cur.left != null || cur.right != null) {
                    nextNum = true;
                }
                qu.offer(cur.left);
                qu.offer(cur.right);
            }
        }
        return sb.substring(0, sb.length() - 1);
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if (data == null || data.length() == 0) {
            return null;
        }
        String[] redata = data.split(",");
        TreeNode root = new TreeNode(Integer.valueOf(redata[0]));
        Queue<TreeNode> qu = new LinkedList<>();
        qu.offer(root);
        int index = 1;
        while (!qu.isEmpty() && index < redata.length) {
            TreeNode cur = qu.poll();
            if (index < redata.length) {
                if (!redata[index].equals("n")) {
                    cur.left = new TreeNode(Integer.valueOf(redata[index]));
                    qu.offer(cur.left);
                }
                ++index;
            } else {
                break;
            }
            if (index < redata.length) {
                if (!redata[index].equals("n")) {
                    cur.right = new TreeNode(Integer.valueOf(redata[index]));
                    qu.offer(cur.right);
                }
                ++index;
            } else {
                break;
            }
        }
        return root;
    }

}
