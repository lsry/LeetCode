#include <algorithm>
#include <array>
#include <vector>
using std::vector;

class ATM {
    constexpr static std::array<int, 5> price{20, 50, 100, 200, 500};
    vector<unsigned long long int> moneys;

    void copyMoney(vector<unsigned long long int> &copyFrom, vector<unsigned long long int> &copyTo) {
        int sz = std::min(copyTo.size(), copyFrom.size());
        for (int i = 0;i < sz;++i) {
            copyTo[i] = copyFrom[i];
        }
    }
public:
    ATM():moneys(5, 0) {}
    
    void deposit(vector<int> banknotesCount) {
        for (int i = 0;i < 5;++i) {
            moneys[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<unsigned long long int> moneys_copy(5, 0);
        copyMoney(moneys, moneys_copy);
        vector<int> r(5, 0);
        for (int i = 4;i >= 0;--i) {
            int c = amount / price[i];
            if (c > moneys[i]) {
                r[i] = moneys[i];
                amount = amount - price[i] *r[i];
                moneys[i] = 0;
            } else {
                r[i] = c;
                moneys[i] -= c;
            }
        }
        if (amount == 0) {
            return r;
        } else {
            copyMoney(moneys_copy, moneys);
            return {-1};
        }
    }
};

int main() {
    ATM a;
    a.deposit({250796,638723,691758,845522,938973});
    a.deposit({215317,848628,182949,784609,30472});
    a.withdraw(722349970);
}