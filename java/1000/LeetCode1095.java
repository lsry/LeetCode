interface MountainArray {
    public int get(int index);
    public int length();
}

public class LeetCode1095 {
    public int findInMountainArray(int target, MountainArray mountainArr) {
        return binSearch(mountainArr, 0, mountainArr.length() - 1, target);
    }
    private int binSearch(MountainArray mountainArr,int left,int right,int target) {
        if (left > right) {
            return -1;
        }
        int mid = (left + right) / 2;
        int midval = mountainArr.get(mid);
        int leftval = mountainArr.get(left);
        if (leftval == target) {
            return left;
        }
        int rightval = mountainArr.get(right);
        if (left == right) {
            return -1;
        } else if (right - left == 1) {
            if (rightval == target) {
                return right;
            } else {
                return -1;
            }
        }
        int midLval = mountainArr.get(mid - 1);
        int midRval = mountainArr.get(mid + 1);
        if (midval == target) {            
            if (leftval < target) {
                int leftIndex = binSearch(mountainArr, left, mid - 1, target);
                if (leftIndex != -1) {
                    return leftIndex;
                }
            }
            return mid;
        } else if (midval < target) {
            if (midLval < midval && midval < midRval) {
                return binSearch(mountainArr, mid + 1, right, target);
            } else if (midLval > midval && midval > midRval) {
                return binSearch(mountainArr, left, mid - 1, target);
            } else {
                return -1;
            }
        } else {
            int ans = -1;
            if (leftval < target) {
                ans = binSearch(mountainArr, left, mid - 1, target);
                if (ans != -1) {
                    return ans;
                }
            }
            if (rightval <= target) {
                ans = binSearch(mountainArr, mid + 1, right, target);
                if (ans != -1) {
                    return ans;
                }
            }
            return ans;
        }
    }
}