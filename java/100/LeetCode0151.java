public class LeetCode0151 {
    public String reverseWords(String s) {
        if (s == null || s.length() == 0) {
            return "";
        }
        String[] arrs = s.trim().split(" "); // 单个空白字符，当有连续空白字符时，产生空字串
        int N = arrs.length;
        for (int i = 0;i < N / 2;i++) {       // 多余，只要后面倒着插入即可
            String t = arrs[i];
            arrs[i] = arrs[N - 1 - i];
            arrs[N - 1 - i] = t;
        }
        StringBuilder sb = new StringBuilder();
        for (String str : arrs) {           
            for (char c : str.toCharArray()) {
                if (c != ' ') {
                    sb.append(c);
                }
            }
            if (sb.length() > 0 && sb.charAt(sb.length() - 1) != ' ') {
                sb.append(' ');
            }
            
        }
        if (sb.length() > 0 && sb.charAt(sb.length() - 1) == ' ') {
            return sb.substring(0, sb.length() - 1);
        } else {
            return sb.toString();
        }
    }
}