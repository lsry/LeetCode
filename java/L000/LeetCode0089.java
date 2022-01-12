package L000;

import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class LeetCode0089 {
    public List<Integer> grayCode(int n) {
        return IntStream.range(0, 1 << n).map(i -> i ^ i >> 1).boxed().collect(Collectors.toList());
    }
}
