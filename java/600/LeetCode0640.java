import java.util.ArrayList;
import java.util.List;

public class LeetCode0640 {
    public String solveEquation(String equation) {
        String[] eqs = equation.split("=");
        int lhs = 0,rhs = 0;
        for (String token : tokens(eqs[0])) {
            if (token.indexOf('x') >= 0) {
                lhs += Integer.parseInt(coff(token));
            } else {
                rhs -= Integer.parseInt(token);
            }
        }
        for (String token : tokens(eqs[1])) {
            if (token.indexOf('x') >= 0) {
                lhs -= Integer.parseInt(coff(token));
            } else {
                rhs += Integer.parseInt(token);
            }
        }
        if (lhs == 0) {
            return (rhs == 0) ? "Infinite solutions" : "No solution";
        }
        return "x=" + (rhs / lhs);
    }

    public String coff(String x) {
        if (x.length() > 1 && x.charAt(x.length() - 2) >= '0' && x.charAt(x.length() - 2) <= '9')
           return x.replace("x", "");
       return x.replace("x", "1");
   }

    public List<String> tokens(String s) {
        List<String> res = new ArrayList<>();
        StringBuilder temp = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (c == '+' || c == '-') {
                if (temp.length() > 0) {
                    res.add(temp.toString());
                }
                temp = new StringBuilder();
                temp.append(c);
            } else if (c == 'x') {
                temp.append(c);
                res.add(temp.toString());
                temp = new StringBuilder();
            } else {
                temp.append(c);
            }
        }
        if (temp.length() > 0) {
            res.add(temp.toString());
        }
        return res;
    }
}