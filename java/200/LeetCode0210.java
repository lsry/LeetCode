import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class LeetCode0210 {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        List<Integer> ans = new ArrayList<>(numCourses);
        boolean[] selected = new boolean[numCourses];
        boolean[] filled = new boolean[numCourses];
        boolean[][] relations = new boolean[numCourses][numCourses];
        for (int[] cur : prerequisites) {
            relations[cur[0]][cur[1]] = true;
        }
        L1:
            for (int i = 0;i < numCourses;++i) {
                if (!filled[i]) {
                    for (int j = 0;j < numCourses;++j) {
                        if (relations[i][j]) {
                            selected[i] = true;
                            if (!helper(relations, selected, j,ans,filled)) {
                                break L1;
                            }
                            relations[i][j] = false;
                            selected[i] = false;
                        }
                    }
                    if (!filled[i]) {
                        ans.add(i);
                        filled[i] = true;
                    }
                }
            }
        if (ans.size() != numCourses) {
            return new int[]{};
        }
        int[] res = new int[numCourses];
        for (int i = 0;i < numCourses;++i) {
            res[i] = ans.get(i);
        }
        return res;
    }

    public boolean helper(boolean[][] relations, boolean[] selected,int row,List<Integer> ans,boolean[] filled) {
        selected[row] = true;
        for (int i = 0;i < relations[row].length;++i) {
            if (relations[row][i]) {
                if (selected[i] || !helper(relations, selected, i,ans,filled)) {
                    return false;
                }
                relations[row][i] = false;
            }
        }
        selected[row] = false;
        if (!filled[row]) {
            ans.add(row);
            filled[row] = true;
        }
        return true;
    }
}