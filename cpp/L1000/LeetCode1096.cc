#include <string>
using std::string;
#include <unordered_set>
#include <vector>
using std::vector;
#include <cctype>
#include <algorithm>

/**
 * S -> S,A | A
 * A -> AB | B
 * B -> {S} | C
 * C -> CD | D
 * D -> a|b|...|z
 */
class Solution {
    string expr;
    std::size_t ez;
    std::size_t index;

    std::unordered_set<string> merge(std::unordered_set<string> &&prev, std::unordered_set<string> &&last) {
        if (prev.empty()) {
            return last;
        } else if (last.empty()) {
            return prev;
        }
        std::unordered_set<string> r;
        for (string const &p1 : prev) {
            for (string const &p2 : last) {
                r.emplace(p1 + p2);
            }
        }
        return r;
    }

    std::unordered_set<string> S() {
        std::unordered_set<string> r = A();
        while (index < ez && expr[index] == ',') {
            ++index;
            std::unordered_set<string> a = A();
            for (string const &s : a) {
                r.emplace(s);
            }
        }
        return r;
    }

    std::unordered_set<string> A() {
        std::unordered_set<string> r = B();
        while (index < ez && (expr[index] == '{' || std::islower(expr[index]))) {
            std::unordered_set<string> b = B();
            r = merge(std::move(r), std::move(b));
        }
        return r;
    }

    std::unordered_set<string> B() {
        if (index >= ez) {
            return std::unordered_set<string>();
        }
        if (expr[index] == '{') {
            ++index;
            std::unordered_set<string> r = S();
            ++index;
            return r;
        }
        string s;
        while (index < ez && std::islower(expr[index])) {
            s.push_back(expr[index]);
            ++index;
        }
        std::unordered_set<string> r;
        r.emplace(s);
        return r;
    }
public:
    vector<string> braceExpansionII(string expression) {
        expr = expression;
        ez = expression.size();
        index = 0;
        std::unordered_set<string> r = S();
        vector<string> v(r.begin(), r.end());
        std::stable_sort(v.begin(), v.end());
        return v;
    }
};