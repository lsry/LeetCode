import java.util.Arrays;

public class LeetCode0167 {
    public int[] twoSum(int[] numbers, int target) {
        for (int i = 0;i < numbers.length - 1;++i) {
            int index = Arrays.binarySearch(numbers, i + 1, numbers.length, target - numbers[i]);
            if (index > i) {
                return new int[]{i + 1,index + 1};
            }
        }
        return new int[]{};
    }
}