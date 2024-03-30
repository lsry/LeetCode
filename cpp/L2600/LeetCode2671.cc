#include <unordered_map>
class FrequencyTracker {
    std::unordered_map<int, int> nums, freqs;
public:
    FrequencyTracker() {}
    
    void add(int number) {
        if (nums.find(number) != nums.end()) {
            int f = nums[number];
            nums[number] = f + 1;
            freqs[f] -= 1;
            freqs[f + 1] += 1;
        } else {
            nums[number] = 1;
            freqs[1] += 1;
        }
    }
    
    void deleteOne(int number) {
        if (nums.find(number) != nums.end()) {
            int f = nums[number];
            if (f > 0) {
                nums[number] = f - 1;
                freqs[f] -= 1;
                freqs[f - 1] += 1;
            }
        }
    }
    
    bool hasFrequency(int frequency) {
        return frequency > 0 && freqs[frequency] > 0;
    }
};