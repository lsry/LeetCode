package L800;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

public class LeetCode0820 {
    /**
     * 1680ms 5.07%
     * 查看某个单词是否是已有单词中的后缀，是则忽略，不是添加入词典
     */
    public int minimumLengthEncodingTLE(String[] words) {
        List<String> ls = new LinkedList<>();
        for (String word : words) {
            boolean flag =true;
            for (String str : ls) {
                if (str.length() >= word.length() && str.substring(str.length() - word.length()).equals(word)) {
                    flag = false;
                    break;
                } else if (str.length() < word.length() && word.substring(word.length() - str.length()).equals(str)) {
                    ls.remove(str);
                    break;
                }
            }
            if (flag) {
                ls.add(word);
            }
        }
        int len = 0;
        for (String str : ls) {
            len += str.length() + 1;
        }
        return len;
    }

    /**
     * 字典树
     * 将每个单词反序插入树中，每个叶结点形成的单词长度+1的和即为所求
     */

    class Node {
        public Node[] children;

        public Node() {
            children = new Node[26];
        }
    }
    class Tire {
        public Node root;
        public Tire() {
            root = new Node();
        }
        public int insert(String word) {
            Node cur = root;
            boolean flag = false;
            for (int i = word.length() - 1;i >= 0;--i) {
                char c = word.charAt(i);
                if (cur.children[c - 'a'] == null) {
                    cur.children[c - 'a'] = new Node();
                    flag = true;
                }
                cur = cur.children[c - 'a'];
            }
            return flag ? word.length() + 1 : 0;
        }
    } 
    public int minimumLengthEncoding(String[] words) {
        Tire tree = new Tire();
        int len = 0;
        Arrays.sort(words,(s1,s2) -> {return s2.length() - s1.length();});
        for (String word : words) {
            len += tree.insert(word);
        }
        return len;
    }
}