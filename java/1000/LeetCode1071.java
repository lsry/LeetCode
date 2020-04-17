public class LeetCode1071 {
    public String gcdOfStrings(String str1, String str2) {
        int N1 = str1.length(), N2 = str2.length();
        String str = N1 < N2 ? str1 : str2;
        for (int i = str.length();i > 0;--i) {
            if (N1 % i == 0 && N2 % i == 0) {
                String temp = str.substring(0, i);
                if (str1.equals(combine(temp,N1 / i)) && str2.equals(combine(temp,N2 / i))) {
                    return temp;
                }
            }
        }
        return "";
    }

    public String combine(String str,int N) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0;i < N;++i) {
            sb.append(str);
        }
        return sb.toString();
    }
}