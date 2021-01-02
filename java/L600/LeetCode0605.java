package L600;

public class LeetCode0605 {
    public boolean canPlaceFlowers1(int[] flowerbed, int n) {
        int plants = 0;
        for (int i = 0;i < flowerbed.length;i++){
            if (flowerbed[i] == 0 && 
            (i - 1 < 0 || flowerbed[i - 1] == 0) && 
            (i + 1 >= flowerbed.length || flowerbed[i + 1] == 0)){
                plants++;
                flowerbed[i] = 1;
            }
        }
        return plants >= n;
    }

    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int plants = 0;
        int zeros = 0;
        int i = 0;
        while (i < flowerbed.length && flowerbed[i] == 0) {
            ++i;
        }
        if (i == flowerbed.length) {
            plants += (i + 1) / 2;
        } else {
            plants += i / 2;
        }
        for (int j = i + 1;j < flowerbed.length;) {
            while (j < flowerbed.length && flowerbed[j] == 0) {
                ++j;
            }
            if (j >= flowerbed.length) {
                break;
            }
            zeros = j - i - 1;
            if (zeros % 2 == 0) {
                zeros -= 1;
            }
            plants += zeros / 2;
            i = j;
            j = j + 1;
        }
        plants += (flowerbed.length - i - 1) / 2;
        return plants >= n;
    }
}