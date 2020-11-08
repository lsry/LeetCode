package L1000;

import util.TreeNode;

public class LeetCode1028 {
    private int index;
    private char[] str;
    public TreeNode recoverFromPreorder(String S) {
        if (S == null || S.length() == 0) {
            return null;
        }
        str = S.toCharArray();
        index = 0;
        return childNode(0);
    }
    private TreeNode childNode(int hopeLevel) {
        if (index >= str.length) {
            return null;
        }
        int level = 0;
        while (index < str.length && str[index] == '-') {
            ++level;
            ++index;
        }
        if (level != hopeLevel) {
            index -= level;
            return null;
        }
        int value = 0;
        while (index < str.length && Character.isDigit(str[index])) {
            value = value * 10 + (str[index] - '0');
            ++index;
        }
        TreeNode node = new TreeNode(value);
        node.left = childNode(hopeLevel + 1);
        node.right = childNode(hopeLevel + 1);
        return node;
    }
}