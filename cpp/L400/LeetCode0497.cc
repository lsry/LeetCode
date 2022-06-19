#include <random>
#include <vector>
using std::vector;

class Solution {
private:
    std::default_random_engine engine;
    vector<vector<int>> &rects;
    vector<int> areas;
public:
    Solution(vector<vector<int>>& rects) : engine(0), rects(rects) {
        areas.push_back(0);
        for (vector<int> &rect : rects) {
            std::size_t az{areas.size()};
            int area = (rect[3] - rect[1] + 1) * (rect[2] - rect[0] + 1); // 覆盖点数
            areas.push_back(area + areas[az - 1]);
        }
    }
    
    vector<int> pick() {
        std::uniform_int_distribution<int> u(1, areas[areas.size() - 1]);
        int area = u(engine);
        int low = 1, high = areas.size() - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (areas[mid] >= area) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        std::uniform_int_distribution<int> u2(rects[high - 1][0], rects[high - 1][2]);
        std::uniform_int_distribution<int> u3(rects[high - 1][1], rects[high - 1][3]);
        return {u2(engine), u3(engine)};
    }
};