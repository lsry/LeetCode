package L1500;

public class LeetCode01576 {
    public String modifyString(String s) {
        if (s == null || s.length() == 0) {
            return s;
        }
        char[] arr = s.toCharArray();
        for (int i = 0;i < arr.length;++i) {
            if (arr[i] == '?') {
                for (int j = 97;j < 123;++j) {
                    char c = (char)j;
                    if ((i == 0 || c != arr[i - 1]) && (i == arr.length - 1 || c != arr[i + 1])) {
                        arr[i] = c;
                        break;
                    }
                    
                }
            }
        }
        return String.valueOf(arr);
    }
}
