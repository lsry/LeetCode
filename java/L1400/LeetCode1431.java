package L1400;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class LeetCode1431 {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        if (candies == null || candies.length == 0) {
            return new ArrayList<>();
        }
        final int maxF = Arrays.stream(candies).max().getAsInt();        
        return Arrays.stream(candies).boxed().map(x -> {
            if (x + extraCandies >= maxF) {
                return Boolean.TRUE;
            } else {
                return Boolean.FALSE;
            }
        }).collect(Collectors.toList());
    }
}