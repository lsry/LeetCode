package L100;

import java.util.ArrayList;
import java.util.List;

public class LeetCode0118 {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> res = new ArrayList<>();
        for (int i = 0;i < numRows;++i) {
            List<Integer> row = new ArrayList<>();
            row.add(1);
            if (i > 0) {
                List<Integer> tmp = res.get(i - 1);
                for (int j = 0;j < tmp.size() - 1;++j) {
                    row.add(tmp.get(j) + tmp.get(j + 1));
                }
                row.add(1);
            }
            res.add(row);
        }
        return res;
    }
}
