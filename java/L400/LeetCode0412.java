package L400;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class LeetCode0412 {
    public List<String> fizzBuzzIter(int n) {
        List<String> res = new ArrayList<>();
        for (int i = 1;i <= n;i++){
            boolean three = i % 3 == 0;
            boolean five = i % 5 == 0;
            if (three && five){
                res.add("FizzBuzz");
            } else if (three){
                res.add("Fizz");
            } else if (five){
                res.add("Buzz");
            } else {
                res.add(String.valueOf(i));
            }
        }
        return res;
    }

    public List<String> fizzBuzz(int n) {
        return IntStream.range(1, n + 1).mapToObj(x -> {
            if (x % 3 == 0 && x % 5 == 0) {
                return "FizzBuzz";
            } else if (x % 3 == 0) {
                return "Fizz";
            } else if (x % 5 == 0) {
                return "Buzz";
            } else {
                return String.valueOf(x);
            }
        }).collect(Collectors.toList());
    }
}