class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children) {
            return -1;
        }
        if (money < children + 7) {
            return 0;
        }
        money -= children;
        int a = money / 7;
        int b = money % 7;
        if (b == 0) {
            return a <= children ? a : children - 1;
        }
        if (a == 0 || a < children - 1 || (a == children - 1 && b != 3)) {
            return a;
        } else if (a <= children) {
            return a - 1;
        } else {
            return children - 1;
        }
    }
};

int main() {
    Solution s;
    s.distMoney(23, 2);
}