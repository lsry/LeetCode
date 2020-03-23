public class LeetCode0836 {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        // 考虑不重叠的情况
        // 以固定矩形四条边作为界
        //        *
        //     ---------  
        //  *  |       |   *
        //     ---------
        //        *
        return !(rec1[2] <= rec2[0] || rec1[1] >= rec2[3] || rec1[0] >= rec2[2] || rec1[3] <= rec2[1]);
    }
}