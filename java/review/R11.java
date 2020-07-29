public class R11 {
    public int minArray(int[] numbers) {
        if (numbers == null || numbers.length == 0) {
            return 0;
        }
        int l = 0, r = numbers.length - 1;
        int min = numbers[0];
        while (l <= r) {
            int mid = l + (r - l) / 2;
            min = Math.min(min, numbers[mid]);
            if (numbers[mid] > numbers[r]) {
                l = mid + 1;
            } else if (numbers[mid] < numbers[l]) {
                r = mid + 1;
            } else {
                for (int i = l;i <= r;++i) {
                    min = Math.min(min, numbers[i]);
                }
                break;
            }
        }
        return min;
    }
}