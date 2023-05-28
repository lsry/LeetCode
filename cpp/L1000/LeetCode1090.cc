#include <vector>
using std::vector;
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int N = values.size();
        vector<int> ids;
        for (int i = 0;i < N;++i) {
            ids.push_back(i);
        }
        std::sort(ids.begin(), ids.end(), [&](int x, int y) {
            return values[x] >= values[y];
        });
        std::unordered_map<int, int> labelCount;
        int count{0};
        int goal{0};
        for (int id : ids) {
            if (count >= numWanted) {
                break;
            }
            auto labelItem{labelCount.find(labels[id])};
            if (labelItem == labelCount.end() || labelItem->second < useLimit) {
                count += 1;
                goal += values[id];
                if (labelItem == labelCount.end()) {
                    labelCount[labels[id]] = 1;
                } else {
                    labelItem->second += 1;
                }
            }
        }
        return goal;
    }
};