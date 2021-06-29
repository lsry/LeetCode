package L700;

import java.util.ArrayList;
import java.util.Deque;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;

public class LeetCode0752 {
    private class Node {
        public String password;
        public int step;

        public Node(String password, int step) {
            this.password = password;
            this.step = step;
        }
    }
    public int openLock(String[] deadends, String target) {
        HashSet<String> deadSet = new HashSet<>();
        for (String dead : deadends) {
            deadSet.add(dead);
        }
        if (deadSet.contains("0000")) {
            return -1;
        }
        boolean[] visits = new boolean[10001];
        Deque<Node> queue = new LinkedList<>();
        queue.offer(new Node("0000", 0));
        visits[0] = true;
        while (!queue.isEmpty()) {
            Node node = queue.poll();
            if (node.password.equals(target)) {
                return node.step;
            }
            List<String> nextWords = getNextWord(node.password);
            for (String nextWord : nextWords) {
                if (!deadSet.contains(nextWord) && visits[Integer.valueOf(nextWord)] == false) {
                    queue.offer(new Node(nextWord, node.step + 1));
                    visits[Integer.valueOf(nextWord)] = true;
                }
            }
        }
        return -1;
    }

    private List<String> getNextWord(String word) {
        List<String> words = new ArrayList<>(8);
        char[] nums = word.toCharArray();
        for (int i = 0;i < 4;++i) {
            if (nums[i] == '9') {
                nums[i] = '0';
                words.add(String.valueOf(nums));
                nums[i] = '9';
            } else {
                nums[i] = (char)(nums[i] + 1);
                words.add(String.valueOf(nums));
                nums[i] = (char)(nums[i] - 1);
            }
            if (nums[i] == '0') {
                nums[i] = '9';
                words.add(String.valueOf(nums));
                nums[i] = '0';
            } else {
                nums[i] = (char)(nums[i] - 1);
                words.add(String.valueOf(nums));
                nums[i] = (char)(nums[i] + 1);
            }
        }
        return words;
    }
}
