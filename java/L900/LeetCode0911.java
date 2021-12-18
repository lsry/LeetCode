package L900;

import java.util.HashMap;

public class LeetCode0911 {}

class TopVotedCandidate {

    private int[] voteNo;
    private int[] times;

    public TopVotedCandidate(int[] persons, int[] times) {
        voteNo = new int[times.length];
        this.times = times;
        int lastNo = persons[0];
        voteNo[0] = persons[0];
        HashMap<Integer,Integer> map = new HashMap<>();
        map.put(persons[0], 1);
        for (int i = 1;i < times.length;++i) {
            int count = map.getOrDefault(persons[i], 0) + 1;
            map.put(persons[i], count);
            if (count >= map.getOrDefault(lastNo, 0)) {
                lastNo = persons[i];
            } 
            voteNo[i] = lastNo;
        }
    }
    
    public int q(int t) {
        int left = 0, right = times.length - 1;
        int res = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (times[mid] <= t) {
                left = mid + 1;
                res = mid;
            } else {
                right = mid - 1;
            }
        }
        return voteNo[res];
    }
}