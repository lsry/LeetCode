#include <vector>
using std::vector;

#include <string>
using std::string;

#include <numeric>

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> grads;
        for (const string &op : ops) {
            if (op == "C") {
                grads.pop_back();
            } else if (op == "D") {
                int x = grads[grads.size() - 1];
                grads.push_back(2 * x);
            } else if (op == "+") {
                int x = grads[grads.size() - 1];
                int y = grads[grads.size() - 2];
                grads.push_back(x + y);
            } else {
                int t = std::stoi(op);
                grads.push_back(t);
            }
        }
        return std::accumulate(grads.begin(), grads.end(), 0);
    }
};