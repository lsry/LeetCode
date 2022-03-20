#include <vector>
using std::vector;

class Bank {
private:
    vector<long long> &balance;
    int count;
public:
    Bank(vector<long long>& balance) : count(balance.size()), balance(balance) {
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (account1 < 1 || account1 > count || account2 < 1 || account2 > count || balance[account1 - 1] < money) {
            return false;
        }
        balance[account1 - 1] -= money;
        balance[account2 - 1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (account < 1 || account > count) {
            return false;
        }
        balance[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (account < 1 || account > count || balance[account - 1] < money) {
            return false;
        }
        balance[account - 1] -= money;
        return true;
    }
};