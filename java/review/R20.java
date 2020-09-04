package review;

public class R20 {
    public boolean isNumber(String s) {
        if (s == null || s.length() == 0) {
            return false;
        }
        char[] nums = s.trim().toCharArray();
        int p = 0;
        if (p < nums.length && (nums[p] == '+' || nums[p] == '-')) {
            ++p;
        }
        if (p >= nums.length) {
            return false;
        }
        boolean hasPoint = false;
        if (nums[p] == '.') {
            ++p;
            hasPoint = true;
        }
        if (p >= nums.length) {
            return false;
        }
        if (Character.isDigit(nums[p])) {
            while (p < nums.length && Character.isDigit(nums[p])) {
                ++p;
            }
            if (p < nums.length && nums[p] == '.') {
                ++p;
                if (hasPoint) {
                    return false;
                }
                if (p < nums.length && Character.isDigit(nums[p])) {
                    while (p < nums.length && Character.isDigit(nums[p])) {
                        ++p;
                    }
                }
            }
        } else {
            return false;
        }
        if (p > 0 && p < nums.length && (nums[p] == 'E' || nums[p] == 'e')) {
            ++p;
            if (p < nums.length && (nums[p] == '+' || nums[p] == '-')) {
                ++p;
            }
            if (p >= nums.length) {
                return false;
            }
            if (p < nums.length && Character.isDigit(nums[p])) {
                while (p < nums.length && Character.isDigit(nums[p])) {
                    ++p;
                }
            }
        }
        return p == nums.length;
    }

    public static void main(String[] args) {
        R20 code = new R20();
        System.out.println("1: " + (code.isNumber("+2.003e-0") == true));
        System.out.println("2: " + (code.isNumber(".") == false));
        System.out.println("3: " + (code.isNumber(".45") == true));
        System.out.println("4: " + (code.isNumber("32.") == true));
        // normal
        System.out.println("5: " + (code.isNumber("+100") == true));
        System.out.println("6: " + (code.isNumber("5e2") == true));
        System.out.println("7: " + (code.isNumber("32.") == true));
        System.out.println("8: " + (code.isNumber("-123") == true));
        System.out.println("9: " + (code.isNumber("-1e-16") == true));
        System.out.println("10: " + (code.isNumber("0123") == true));
        // error
        System.out.println("11: " + (code.isNumber("12e") == false));
        System.out.println("12: " + (code.isNumber("1a3.14") == false));
        System.out.println("13: " + (code.isNumber("1.2.3") == false));
        System.out.println("14: " + (code.isNumber("+-5") == false));
        System.out.println("15: " + (code.isNumber("12e+5.4") == false));
        System.out.println("16: " + (code.isNumber("e9") == false));

        System.out.println("17: " + (code.isNumber("1 ") == true));
        System.out.println("18: " + (code.isNumber("+e3") == false));
        System.out.println("19: " + (code.isNumber(".e3") == false));
    }
}