import java.util.HashMap;
import java.util.Map;

public class LeetCode0914{
    public boolean hasGroupsSizeVliance(int[] deck) {
        Map<Integer,Integer> hii = new HashMap<>();
        for (int card : deck){
            hii.put(card, hii.getOrDefault(card, 0) + 1);
        }
        int max = 0;
        
        for (Map.Entry<Integer,Integer> entry : hii.entrySet()){
            max = Math.max(max, entry.getValue());
        }
        for (int i = 2;i <= max;i++){
            boolean flag = true;
            for (Map.Entry<Integer,Integer> entry : hii.entrySet()){
                if (entry.getValue() % i != 0){
                    flag = false;
                    break;
                }
            }
            if (flag){
                return true;
            }
        }
        return false;
    }

    // 在一组数中寻找能被所有整数整除，即为最大公约数
    public boolean hasGroupsSizeX(int[] deck) {
        Map<Integer,Integer> hii = new HashMap<>();
        for (int card : deck){
            hii.put(card, hii.getOrDefault(card, 0) + 1);
        }
        int t = 0;
        for (Map.Entry<Integer,Integer> entry : hii.entrySet()) {
            t = gcd(t,entry.getValue());
        }
        return t >= 2;
    }

    public int gcd(int a,int b) {
        if (b < a) {
            int c = a;
            a = b;
            b = c;
        }
        return a == 0 ? b : gcd(a,b % a);
    }
}