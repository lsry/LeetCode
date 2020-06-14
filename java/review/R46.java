public class R46 {
    public int translateNum(int num) {
        return counts(String.valueOf(num), 0);
    }

    private int counts(String snum, int cur) {
        if (cur >= snum.length()) {
            return 0;
        } else if (cur == snum.length() - 1) {
            return 1;
        }
        char cv1 = snum.charAt(cur);
        char cv2 = snum.charAt(cur + 1);
        int n2 = 0;
        if (cv1 == '1' || (cv1 == '2' && cv2 < '6')) {
            if (cur == snum.length() - 2) {
                return 2;
            }
            n2 = counts(snum, cur + 2);
        }
        return counts(snum, cur + 1) + n2;
    }
}