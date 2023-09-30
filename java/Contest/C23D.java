package Contest;

public class C23D {
    public int countLargestGroup(int n) {
        int[] arr = new int[50];
        for (int i = 1;i <= n;++i) {
            int sum = 0;
            int t = i;
            while (t != 0) {
                sum += t % 10;
                t = t / 10;
            }
            arr[sum]++;
        }
        int max = 0;
        for (int a : arr) {
            if (a > max) {
                max = a;
            }
        }
        int count = 0;
        for (int a : arr) {
            if (a == max) {
                ++count;
            }
        }
        return count;
    }

    public boolean canConstruct(String s, int k) {
        int[] chs = new int[26];
        for (char c : s.toCharArray()) {
            chs[c - 'a']++;
        }
        int even = 0, odd = 0;
        for (int c : chs) {
            if (c % 2 == 0) {
                even += c / 2;
            } else {
                odd++;
                even += (c - 1) / 2;
            }
        }
        if (even >= k && odd <= k) {
            return true;
        } else if (even < k) {
            if (odd >= k - even && odd <= k) {
                return true;
            } else if (odd < k - even) {
                for (int i = 1;i <= even;++i) {
                    if (odd + 2 * i >= k - (even - i) && odd + 2 * i - k <= 0) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
}