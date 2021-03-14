package L300;

public class LeetCode0331 {
    private int i;
    public boolean isValidSerialization(String preorder) {
        if (preorder == null || preorder.length() == 0) {
            return true;
        }
        i = 0;
        return isValidIndex(preorder) && i >= preorder.length();
    }

    private boolean isValidIndex(String tree) {
        final int N = tree.length();
        while (i < N && tree.charAt(i) == ' ') {
            ++i;
        }
        if (i >= N) {
            return false;
        }
        if (tree.charAt(i) == '#') {
            while (i < N && tree.charAt(i) != ',') {
                ++i;
            }
            ++i;
            return true;
        } else if (Character.isDigit(tree.charAt(i))) {
            while (i < N && tree.charAt(i) != ',') {
                ++i;
            }
            ++i;
            boolean flag = isValidIndex(tree);
            flag &= isValidIndex(tree);
            return flag;
        }
        return false;
    }
}
