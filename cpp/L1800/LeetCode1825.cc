#include <vector>
#include <queue>
#include <set>

class MKAverage {
    long long int middleSum;
    int M;
    int K;
    std::queue<int> nums;
    std::multiset<int> smalls, middles, larges;
public:
    MKAverage(int m, int k): M(m), K(k), middleSum(0LL) {}
    
    void addElement(int num) {
        nums.push(num);
        if (nums.size() <= M) {
            middles.insert(num);
            middleSum += num;
            if (nums.size() == M) {
                for (int i = 0;i < K;++i) {
                    auto it = middles.begin();
                    smalls.insert(*it);
                    middleSum -= *it;
                    middles.erase(it);
                }
                for (int i = 0;i < K;++i) {
                    auto it = std::prev(middles.end());
                    larges.insert(*it);
                    middleSum -= *it;
                    middles.erase(it);
                }
            }
        } else {
            auto sit = std::prev(smalls.end());
            auto lit = larges.begin();
            if (*sit > num) {
                middles.insert(*sit);
                middleSum += *sit;
                smalls.erase(sit);
                smalls.insert(num);
            } else if (*lit < num) {
                middles.insert(*lit);
                middleSum += *lit;
                larges.erase(lit);
                larges.insert(num);
            } else {
                middles.insert(num);
                middleSum += num;
            }
            int e = nums.front();
            nums.pop();
            if (smalls.count(e) > 0) {
                smalls.erase(smalls.find(e));
                smalls.insert(*middles.begin());
                middleSum -= *middles.begin();
                middles.erase(middles.begin());
            } else if (larges.count(e) > 0) {
                larges.erase(larges.find(e));
                auto it = std::prev(middles.end());
                larges.insert(*it);
                middleSum -= *it;
                middles.erase(it);
            } else {
                middleSum -= e;
                middles.erase(middles.find(e));
            }
        }
    }
    
    int calculateMKAverage() {
        if (nums.size() < M) {
            return -1;
        }
        return middleSum / (M - 2 * K);
    }
};