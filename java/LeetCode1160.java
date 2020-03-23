public class LeetCode1160 {
    public int countCharacters(String[] words, String chars) {
        int[] sou = new int[26];
        for (char c : chars.toCharArray()) {
            sou[c - 'a']++;
        }
        int len = 0;
        for (String word : words) {
            int[] aim = new int[26];
            for (char c : word.toCharArray()) {
                aim[c - 'a']++;
            }
            if (compare(sou,aim)) {
                len += word.length();
            }
        }
        return len;
    }

    public boolean compare(int[] sou,int[] aim) {
        for (int i = 0;i < sou.length;++i) {
            if (aim[i] > sou[i]) {
                return false;
            }
        }
        return true;
    }
}