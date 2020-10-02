import java.util.HashMap;
import java.util.HashSet;

public class LeetCode0771{
    /**
     * 使用 Map 统计宝石数目
     */
    public int getJewelStones(String J,String S){
        HashMap<Character,Integer> jewels = new HashMap<>(50);
        for(int i = 0;i < J.length();i++){
            Character ch = J.charAt(i);
            if (!jewels.containsKey(ch) && Character.isLetter(ch)){
                jewels.put(ch, 0);
            }
        }
        for (int i = 0;i < S.length();i++){
            Character ch = S.charAt(i);
            if (jewels.containsKey(ch)){
                jewels.put(ch, jewels.get(ch) + 1);
            }
        }
        int count = 0;
        for (Integer value : jewels.values()){
            count += value;
        }
        return count;
    } 

    public int numJewelsInStones(String J, String S) {
        HashSet<Character> set = new HashSet<>();
        for (char c : J.toCharArray()) {
            set.add(c);
        }
        int count = 0;
        for (char c : S.toCharArray()) {
            if (set.contains(c)) {
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        LeetCode0771 code = new LeetCode0771();
        System.out.println(code.getJewelStones("aAA", "aAAbbbb"));
        System.out.println(code.getJewelStones("z", "ZZZ")); 
        System.out.println(code.getJewelStones("Z12", "ZZZ12")); 
        System.out.println(code.getJewelStones("", "ZZZ12")); 
    }
}