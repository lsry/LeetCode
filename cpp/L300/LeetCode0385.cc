#include <vector>
using std::vector;

#include <string>
using std::string;

class NestedInteger {
    public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class Solution {
private:
    std::size_t sz{0};
    std::size_t idx{0};

    NestedInteger processInteger(string &s) {
        bool pos = true;
        if (s[idx] == '-') {
            pos = false;
            ++idx;
        }
        int num = 0;
        while (idx < sz && s[idx] >= '0' && s[idx] <= '9') {
            num = num * 10 + (s[idx] - '0');
            ++idx;
        }
        if (!pos) {
            num *= -1;
        }
        return NestedInteger(num);
    }

    NestedInteger processList(string &s) {
        ++idx;
        NestedInteger cur;
        while (idx < sz && s[idx] != ']') {
            if (s[idx] == '[') {
                NestedInteger next = processList(s);
                cur.add(next);
            } else if (s[idx] == '-' || s[idx] >='0' && s[idx] <= '9') {
                NestedInteger next = processInteger(s);
                cur.add(next);
            }
            if (idx < sz && s[idx] == ',') {
                ++idx;
            }
        }
        ++idx;
        return cur;
    }

public:
    NestedInteger deserialize(string s) {
        sz = s.size();
        if (sz == 0) {
            return NestedInteger(0);
        }
        if (s[0] == '[') {
            return processList(s);
        } else {
            return processInteger(s);
        }
    }
};