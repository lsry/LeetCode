#include <vector>
using std::vector;


 // This is the custom function interface.
 // You should not implement it, or speculate about its implementation
 class CustomFunction {
 public:
     // Returns f(x, y) for any given positive integers x and y.
     // Note that f(x, y) is increasing with respect to both x and y.
     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
     int f(int x, int y);
};

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> res;
        for (int i = 1;i <= 1000;++i) {
            int jl = 1, jh = 1000;
            while (jl <= jh) {
                int jm = (jl + jh) / 2;
                int fv = customfunction.f(i, jm);
                if (fv == z) {
                    res.push_back({i, jm});
                    break;
                } else if (fv < z) {
                    jl = jm + 1;
                } else {
                    jh = jm - 1;
                }
            }
        }
        return res;
    }
};