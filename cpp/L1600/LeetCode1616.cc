#include <string>
using std::string;

class Solution {
    bool check(string const &a, string const &b) {
        int sz = a.size();
        int high{sz / 2};
        int low = high;
        if (sz % 2 == 0) {
            low -= 1;
        }
        while (low >= 0 && a[low] == a[high]) {
            --low;
            ++high;
        }
        if (low < 0) {
            return true;
        }
        while (low >= 0 && a[low] == b[high]) {
            --low;
            ++high;
        }
        if (low < 0) {
            return true;
        }
        high = sz / 2;
        low = high;
        if (sz % 2 == 0) {
            low -= 1;
        }
        while (high < sz && a[low] == a[high]) {
            --low;
            ++high;
        }
        if (high >= sz) {
            return true;
        }
        while (high < sz && a[high] == b[low]) {
            ++high;
            --low;
        }
        return high >= sz;
    }
public:
    bool checkPalindromeFormation(string a, string b) {
        return check(a, b) || check(b, a);
    }
};