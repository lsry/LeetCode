package L1600;

public class LeetCode1629 {
    public char slowestKey(int[] releaseTimes, String keysPressed) {
        char maxChar = 'a';
        int maxTime = 0;
        int lastTime = 0;
        for (int i = 0;i < releaseTimes.length;++i) {
            char c = keysPressed.charAt(i);
            int time = releaseTimes[i] - lastTime;
            if (maxTime < time || (time == maxTime && maxChar < c)) {
                maxChar = c;
                maxTime = time;
            }
            lastTime = releaseTimes[i];
        }
        return maxChar;
    }
}
