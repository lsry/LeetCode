#include <utility>
#include <vector>
class SnapshotArray {
    int term;
    std::vector<std::vector<std::pair<int, int>>> nums;
public:
    SnapshotArray(int length): term(0), nums(length, std::vector<std::pair<int, int>>()) {
        for (int i = 0;i < length;++i) {
            nums[i].emplace_back(std::pair<int, int>(0, 0));
        }
    }
    
    void set(int index, int val) {
        if (nums[index].back().first == term) {
            nums[index].back().second = val;
        } else {
            nums[index].emplace_back(std::pair<int, int>(term, val));
        }
    }
    
    int snap() {
        int snapId = term;
        ++term;
        return snapId;
    }
    
    int get(int index, int snap_id) {
        int low = 0, high = nums[index].size();
        while (low < high) {
            int mid = (low + high) / 2;
            if (nums[index][mid].first > snap_id) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return nums[index][low - 1].second;
    }
};