import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class R1603 {
    public double[] intersection(int[] start1, int[] end1, int[] start2, int[] end2) {
        int D = det(end1[0] - start1[0],start2[0] - end2[0],end1[1] - start1[1],start2[1] - end2[1]);
        if (D != 0) { // 相交
            int fen1 = det(end1[0] - start1[0],start2[0] - start1[0],end1[1] - start1[1],start2[1] - start1[1]);
            int fen2 = det(start2[0] - start1[0],start2[0] - end2[0],start2[1] - start1[1],start2[1] - end2[1]);
            double t1 = fen1 / (D * 1.0);
            double t2 = fen2 / (D * 1.0);
            if (t1 >= 0.0 && t1 <= 1.0 && t2 >= 0.0 && t2 <= 1.0) {
                return new double[]{start2[0] + t1 * (end2[0] - start2[0]),start2[1] + t1 * (end2[1] - start2[1])};
            } else {
                return new double[]{};
            }
        // 平行不共线
        } else if ((start2[0] - start1[0]) * (end1[1] - start1[1]) != (end1[0] - start1[0]) * (start2[1] - start1[1])) {
            return new double[]{};
        } else {
            List<int[]> res = new ArrayList<>();
            double t1 = -1.0,t2 = -1.0;
            if (end1[0] != start1[0]) {
                t1 = 1.0 * (start2[0] - start1[0]) / (end1[0] - start1[0]);
                t2 = 1.0 * (end2[0] - start1[0]) / (end1[0] - start1[0]);
            } else {
                t1 = 1.0 * (start2[1] - start1[1]) / (end1[1] - start1[1]);
                t2 = 1.0 * (end2[1] - start1[1]) / (end1[1] - start1[1]);
            }
            if (t1 >= 0 && t1 <= 1) {
                res.add(start2);
            }
            if (t2 >= 0 && t2 <= 1) {
                res.add(end2);
            }
            if (end2[0] != start2[0]) {
                t1 = 1.0 * (start1[0] - start2[0]) / (end2[0] - start2[0]);
                t2 = 1.0 * (end1[0] - start2[0]) / (end2[0] - start2[0]);
            } else {
                t1 = 1.0 * (start1[1] - start2[1]) / (end2[1] - start2[1]);
                t2 = 1.0 * (end1[1] - start2[1]) / (end2[1] - start2[1]);
            }
            if (t1 >= 0 && t1 <= 1) {
                res.add(start1);
            }
            if (t2 >= 0 && t2 <= 1) {
                res.add(end1);
            }
            if (res.isEmpty()) {
                return new double[]{};
            }
            Collections.sort(res, (int[]a, int[]b) -> {
                if (a[0] != b[0]) {
                    return a[0] - b[0];
                } else {
                    return a[1] - b[1];
                }
            });
            int[] tar = res.get(0);
            return new double[]{tar[0],tar[1]};
        }
    }

    public int det(int a,int b,int c,int d) {
        return a * d - b * c;
    }
}