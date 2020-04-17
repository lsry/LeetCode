public class LeetCode1103 {
    public int[] distributeCandies(int candies, int num_people) {
        int[] res = new int[num_people];
        int i = 0;
        while (candies > 0) {
            if (candies >= i + 1) {
                res[i % num_people] += i + 1;
                candies -= i + 1;
            } else if (candies > 0) {
                res[i % num_people] += candies;
                candies = 0;
            }
            i = i + 1;
        }
        return res;
    }
}