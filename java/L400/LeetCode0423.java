package L400;

public class LeetCode0423 {
    /**
     * Ax = B
     * x = A^-1 * B
     * A: 15 * 10 matrix，每一行为数字总数，每一列为字母出现的次数
     * B: 各字母总数目， 15 * 1 matrix
     */
    public String originalDigitsMatrix(String s) {
        int[] chars = new int[26 + 'a'];
        for (char ch : s.toCharArray()){
            chars[ch]++;
        }
        int[] num = new int[10];
        num[0] = chars['z'];
        num[1] = chars['o'] - chars['z'] - chars['w'] - chars['u'];
        num[2] = chars['w'];
        num[3] = chars['r'] - chars['z'] - chars['u'];
        num[4] = chars['u'];
        num[5] = chars['f'] - chars['u'];
        num[6] = chars['x'];
        num[7] = chars['s'] - chars['x'];
        num[8] = chars['g'];
        num[9] = chars['i'] - (chars['f'] - chars['u']) - chars['x'] - chars['g'];
        StringBuilder sb = new StringBuilder();
        for (int i = 0;i < 10;i++){
            for (int j = 0;j < num[i];j++){
                sb.append(i);
            }
        }
        return sb.toString();
    }

    /**
     * 这十个英文单词可形成一个拓扑排序图，每个节点代表一个字母，边由于单词而形成依赖关系
     * 依次寻找只包含一个单词的节点，即可得到结果
     */
    public String originalDigits(String s) {
        int[] chars = new int[26];
        int[] digits = new int[10];
        for (char ch : s.toCharArray()){
            chars[ch - 'a']++;
        }
        if (chars['z' - 'a'] > 0) {
            digits[0] = chars['z' - 'a'];
            chars['e' - 'a'] -= chars['z' - 'a'];
            chars['r' - 'a'] -= chars['z' - 'a'];
            chars['o' - 'a'] -= chars['z' - 'a'];
        }
        if (chars['x' - 'a'] > 0) {
            digits[6] = chars['x' - 'a'];
            chars['s' - 'a'] -= chars['x' - 'a'];
            chars['i' - 'a'] -= chars['x' - 'a'];
        }
        if (chars['u' - 'a'] > 0) {
            digits[4] = chars['u' - 'a'];
            chars['r' - 'a'] -= chars['u' - 'a'];
            chars['o' - 'a'] -= chars['u' - 'a'];
            chars['f' - 'a'] -= chars['u' - 'a'];
        }
        if (chars['f' - 'a'] > 0) {
            digits[5] = chars['f' - 'a'];
            chars['i' - 'a'] -= chars['f' - 'a'];
            chars['e' - 'a'] -= chars['f' - 'a'];
            chars['v' - 'a'] -= chars['f' - 'a'];
        }
        if (chars['s' - 'a'] > 0) {
            digits[7] = chars['s' - 'a'];
            chars['e' - 'a'] -= chars['s' - 'a'] * 2;
            chars['v' - 'a'] -= chars['s' - 'a'];
            chars['n' - 'a'] -= chars['s' - 'a'];
        }
        if (chars['w' - 'a'] > 0) {
            digits[2] = chars['w' - 'a'];
            chars['t' - 'a'] -= chars['w' - 'a'];
            chars['o' - 'a'] -= chars['w' - 'a'];
        }
        if (chars['g' - 'a'] > 0) {
            digits[8] = chars['g' - 'a'];
            chars['e' - 'a'] -= chars['g' - 'a'];
            chars['i' - 'a'] -= chars['g' - 'a'];
            chars['h' - 'a'] -= chars['g' - 'a'];
            chars['t' - 'a'] -= chars['g' - 'a'];
        }
        if (chars['h' - 'a'] > 0) {
            digits[3] = chars['h' - 'a'];
            chars['e' - 'a'] -= chars['h' - 'a'] * 2;
            chars['r' - 'a'] -= chars['h' - 'a'];
            chars['t' - 'a'] -= chars['h' - 'a'];
        }
        if (chars['i' - 'a'] > 0) {
            digits[9] = chars['i' - 'a'];
            chars['n' - 'a'] -= chars['i' - 'a'] * 2;
            chars['e' - 'a'] -= chars['i' - 'a'];
        }
        if (chars['e' - 'a'] > 0) {
            digits[1] = chars['e' - 'a'];
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0;i < 10;i++){
            for (int j = 0;j < digits[i];j++){
                sb.append(i);
            }
        }
        return sb.toString();
    }
}