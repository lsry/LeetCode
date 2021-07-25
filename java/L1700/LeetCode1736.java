package L1700;

public class LeetCode1736 {

    public String maximumTime(String time) {
        char[] ctime = time.toCharArray();
        if (ctime[0] == '?') {
            ctime[0] = ctime[1] == '?' || ctime[1] != '?' && ctime[1] < '4' ? '2' : '1';
        }
        if (ctime[1] == '?') {
            ctime[1] = ctime[0] == '2' ? '3' : '9';
        }
        if (ctime[3] == '?') {
            ctime[3] = '5';
        }
        if (ctime[4] == '?') {
            ctime[4] = '9';
        }
        return String.valueOf(ctime);
    }
}