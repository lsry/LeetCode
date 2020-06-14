import java.util.ArrayList;
import java.util.List;

public class LeetCode0990 {
    private int[] chars = new int[26];
    private int[] weights = new int[26];

    public int weight_find(int i) {
        while (i != chars[i]) {
            i = chars[i];
        }
        return i;
    }

    public void weight_union(int p,int q) {
        int pid = weight_find(p);
        int qid = weight_find(q);
        if (pid != qid) {
            if (weights[p] < weights[q]) {
                chars[pid] = qid;
                weights[q] += weights[p];
            } else {
                chars[qid] = pid;
                weights[p] += weights[q];
            }
        }
    }

    public boolean weight_connected(int p,int q) {
        return weight_find(p) == weight_find(q);
    }

    public boolean equationsPossible(String[] equations) {
        if (equations == null || equations.length == 0) {
            return true;
        }
        for (int i = 0;i < 26;++i) {
            chars[i] = i;
            weights[i] = 1;
        }
        List<String> notEqual = new ArrayList<>();
        for (String equation : equations) {
            if (equation.charAt(1) == '!') {
                notEqual.add(equation);
            } else {
                weight_union(equation.charAt(0) - 'a', equation.charAt(3) - 'a');
            }
        }
        for (String equation : notEqual) {
            int v1 = equation.charAt(0) - 'a';
            int v2 = equation.charAt(3) - 'a';          
            if (v1 == v2 || weight_connected(v1, v2)) {
                return false;
            }
        }
        return true;
    }
}