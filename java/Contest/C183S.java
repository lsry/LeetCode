package Contest;

import java.util.ArrayList;
import java.util.List;

public class C183S {
    public List<Integer> minSubsequence(int[] nums) {
        List<Integer> res = new ArrayList<>();
        if (nums == null || nums.length == 0) {
            return res;
        } else if (nums.length == 1) {
            res.add(nums[0]);
            return res;
        }
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }
        return res;
    }

    public int numSteps(String s) {
        int N = s.length();
        if (s == null || N <= 1) {
            return 0;
        }
        char[] chs = new char[N * 2];
        for (int i = N - 1;i >= 0;--i) {
            chs[N + i] = s.charAt(i);
        }
        for (int i = 0;i < N;++i) {
            chs[i] = '0';
        }
        int head = N, tail = chs.length - 1;
        int step = 0;
        while (head != tail) {
            if (chs[tail] == '1') {
                boolean ward = true;
                for (int i = tail;i >= head;--i) {
                    if (chs[i] == '1') {
                        if (ward) {
                            chs[i] = '0';
                            ward = true;
                        }
                    } else {
                        if (ward) {
                            chs[i] = '1';
                            ward = false;
                        }
                    }
                }
                if (ward) {
                    head--;
                    chs[head] = '1';
                }
            } else {
                --tail;
            }
            ++step;
        }
        return step;
    }

    // error
    public String longestDiverseString(int a, int b, int c) {
        int[] arr = new int[]{a,b,c};
        StringBuffer sb = new StringBuffer();
        int state = 0;
        if (arr[0] >= 2) {
            sb.append("aa");
            state = 0;
            arr[0] -= 2;
        } else if (arr[1] >= 2) {
            sb.append("bb");
            state = 1;
            arr[1] -= 2;
        } else if (arr[2] >= 2) {
            sb.append("cc");
            state = 2;
            arr[2] -= 2;
        } else if (arr[0] == 1) {
            sb.append('a');
            arr[0] = 0;
            state = 0;
        } else if (arr[1] == 1) {
            sb.append('b');
            arr[1] = 0;
            state = 1;
        } else if (arr[2] == 1) {
            sb.append('c');
            arr[2] = 0;
            state = 2;
        }
        while (arr[0] >= 0 || arr[1] >= 0 || arr[2] >= 0) {
            if (arr[0] >= 2 && state != 0) {
                sb.append("aa");
                arr[0] -= 2;
                state = 0;
            } else if (arr[1] >= 2 && state != 1) {
                sb.append("bb");
                arr[1] -= 2;
                state = 1;
            } else if (arr[2] >= 2 && state!= 2) {
                sb.append("cc");
                arr[2] -= 2;
                state = 2;
            } else if (arr[0] == 1 && state != 0) {
                sb.append('a');
                arr[0] = 0;
                state = 0;
            } else if (arr[1] == 1 && state != 1) {
                sb.append('b');
                arr[1] = 0;
                state = 1;
            } else if (arr[2] == 1 && state != 2) {
                sb.append('c');
                arr[2] = 0;
                state = 2;
            } else {
                break;
            }
        }
        return sb.toString();
    }
}