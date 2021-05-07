package L1700;

import java.util.Arrays;

public class LeetCode1723 {
    public int minimumTimeRequired(int[] jobs, int k) {
        Arrays.sort(jobs);
        int low = 0, high = jobs.length - 1;
        while (low < high) {
            int t = jobs[low];
            jobs[low] = jobs[high];
            jobs[high] = t;
            ++low;
            --high;
        }
        low = jobs[0];
        high = Arrays.stream(jobs).sum();
        while (low <= high) {
            int mid = (low + high) / 2;
            if (check(jobs, k, mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

    private boolean check(int[] jobs, int k, int limit) {
        int[] workloads = new int[k];
        return trace(jobs, 0, workloads, limit);
    }

    private boolean trace(int[] jobs, int index, int[] workloads, int limit) {
        if (index >= jobs.length) {
            return true;
        }
        int cur = jobs[index];
        for (int i = 0;i < workloads.length;++i) {
            if (workloads[i] + cur <= limit) {
                workloads[i] += cur;
                if (trace(jobs, index + 1, workloads, limit)) {
                    return true;
                }
                workloads[i] -= cur;
            }
            if (workloads[i] == 0 || workloads[i] + cur == limit) {
                break;
            }
        }
        return false;
    }
}
