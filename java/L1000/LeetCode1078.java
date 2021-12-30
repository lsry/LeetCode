package L1000;

import java.util.ArrayList;
import java.util.List;

public class LeetCode1078 {
    public String[] findOcurrences(String text, String first, String second) {
        List<String> res = new ArrayList<>();
        String[] arr = text.split(" ");
        for (int i = 0;i < arr.length - 2;++i) {
            if (first.equals(arr[i]) && second.equals(arr[i + 1])) {
                res.add(arr[i + 2]);
            }
        } 
        return res.stream().toArray(String[]::new);
    }
}
