package review;

import java.util.Objects;

public class R1618 {
    public boolean patternMatching(String pattern, String value) {
        int VN = value.length(), PN = pattern.length();
        if (VN == 0 && PN == 0) {
            return true;
        } else if (PN == 0 && VN != 0) {
            return false;
        }
        char[] pchs = pattern.toCharArray();
        int ca = 0, cb = 0;
        for (char ch : pchs) {
            if (ch == 'a') {
                ++ca;
            } else {
                ++cb;
            }
        }
        if (PN != 0 && VN == 0) {
            return ca == 0 || cb == 0;
        }
        if (ca < cb) {
            int t = ca;
            ca = cb;
            cb = t;
            for (int i = 0;i < pchs.length;++i) {
                pchs[i] = (pchs[i] == 'a') ? 'b' : 'a';
            }
        }
        // 满足二元一次方程 la * ca + (PN - ca) * cb == VN
        for (int la = 0;la * ca <= VN;++la) {
            int rest = VN - la * ca;
            if ((cb == 0 && rest == 0) || (cb != 0 && rest % cb == 0)) {
                int lb = cb == 0 ? 0 : (rest / cb);
                boolean correct = true;
                String va = "", vb = "";
                int pos = 0;
                for (char ch : pchs) {
                    if (ch == 'a') {
                        String cur = value.substring(pos, pos + la);
                        if (va.length() == 0) {
                            va = cur;
                        } else {
                            if (!Objects.equals(va, cur)) {
                                correct = false;
                                break;
                            }                           
                        }
                        pos += la;
                    } else {
                        String cur = value.substring(pos,pos + lb);
                        if (vb.length() == 0) {
                            vb = cur;
                        } else {
                            if (!Objects.equals(vb, cur)) {
                                correct = false;
                                break;
                            }
                        }
                        pos += lb;
                    }
                }
                if (correct && !Objects.equals(va, vb)) {
                    return true;
                }
            }           
        }
        return false;
    }

    public static void main(String[] args) {
        R1618 rob = new R1618();
        System.out.println("1: " + (rob.patternMatching("", "x") == false));
        System.out.println("2: " + (rob.patternMatching("ab", "") == false));
        System.out.println("3: " + (rob.patternMatching("a", "") == true));
        System.out.println("4: " + (rob.patternMatching("aaa", "dogdogdog") == true));
        System.out.println("5: " + (rob.patternMatching("", "") == true));
        System.out.println("6: " + (rob.patternMatching("bbbbbbbbbbbbbbabbbbb", 
            "ppppppppppppppjsftcleifftfthiehjiheyqkhjfkyfckbtwbelfcgihlrfkrwireflijkjyppppg") == true));
        System.out.println("7: " + (rob.patternMatching("bbbbbbbbabbbbbbbbbbbabbbbbbba", 
            "zezezezezezezezezkxzezezezezezezezezezezezkxzezezezezezezezkx") == true));
        System.out.println("8: " + (rob.patternMatching("abb", "dryqxzysggjljxdxag") == true));
    }
}