package L100;

public class LeetCode0152 {
    public int maxProduct(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        return divide(nums, 0, nums.length - 1)[0];
    }
    public int[] divide(int[] nums, int p, int q) {
        if (p == q) {
            return new int[]{nums[p], nums[p]};
        } else if (p < q) {
            int mid = (p + q) / 2;
            int lp[] = divide(nums, p, mid);
            int rp[] = divide(nums, mid + 1, q);
            int mp[] = midProduct(nums,p,mid,q);
            return new int[]{Math.max(Math.max(lp[0], rp[0]), mp[0]),
                             Math.min(Math.min(lp[1], rp[1]), mp[1])};
        }
        return new int[]{0,0};
    }
    public int[] midProduct(int[] nums, int p, int mid, int q) {
        int lpx = Integer.MIN_VALUE, lpn = Integer.MAX_VALUE, pro = 1;
        for (int i = mid;i >= p;--i) {
            pro *= nums[i];
            if (pro >= lpx) {
                lpx = pro;
            }
            if (pro <= lpn) {
                lpn = pro;
            }
        }
        pro = 1;
        int rpx = Integer.MIN_VALUE, rpn = Integer.MAX_VALUE;
        for (int i = mid + 1;i <= q;++i) {
            pro *= nums[i];
            if (pro >= rpx) {
                rpx = pro;
            }
            if (pro <= rpn) {
                rpn = pro;
            }
        }
        return new int[]{Math.max(lpx * rpx, lpn * rpn),
            Math.min(Math.min(lpx * rpx,lpn * rpn), Math.min(lpx * rpn, lpn * rpx))};
    }
}