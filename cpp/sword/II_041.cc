#include <queue>

class MovingAverage {
private:
    int size_;
    int sum;
    std::queue<int> nums;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size): size_(size), sum(0) {}
    
    double next(int val) {
        if (nums.size() >= size_) {
            int del = nums.front();
            nums.pop();
            nums.push(val);
            sum = sum - del + val;
        } else {
            nums.push(val);
            sum += val;
        }
        return sum * 1.0 / std::min(size_, (int)nums.size());
    }
};