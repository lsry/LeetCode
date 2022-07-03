#include <vector>
using std::vector;

#include <string>
using std::string;

#include <unordered_set>

class Solution {
private:
    vector<int> dfs(vector<vector<vector<int>>> &mem, vector<int> &ops, int left, int right) {
        if (mem[left][right].empty()) {
            if (left == right) {
                mem[left][right].push_back(ops[left]);
            } else {
                for (int i{left + 1}; i < right;i += 2) {
                    vector<int> lc = dfs(mem, ops, left, i - 1);
                    vector<int> rc = dfs(mem, ops, i + 1, right);
                    for (int ln : lc) {
                        for (int rn : rc) {
                            int n = 0;
                            if (ops[i] == -1) {
                                n = rn + ln;
                            } else if (ops[i] == -2) {
                                n = ln - rn;
                            } else if (ops[i] == -3) {
                                n = ln * rn;
                            }
                            mem[left][right].push_back(n);
                        }
                    }
                }
            }
        }
        return mem[left][right];
    }
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ops;
        std::size_t ez{expression.size()};
        for (std::size_t i{0};i < ez;++i) {
            if (expression[i] >= '0' && expression[i] <= '9') {
                int num = 0;
                while (i < ez && expression[i] >= '0' && expression[i] <= '9') {
                    num = num * 10 + (expression[i] - '0');
                    ++i;
                }
                --i;
                ops.push_back(num);
            } else if (expression[i] == '+') {
                ops.push_back(-1);
            } else if (expression[i] == '-') {
                ops.push_back(-2);
            } else if (expression[i] == '*') {
                ops.push_back(-3);
            }
        }
        vector<vector<vector<int>>> mem(ops.size(), vector<vector<int>>(ops.size()));
        return dfs(mem, ops, 0, ops.size() - 1);
    }
};