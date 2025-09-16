#include <queue>
#include <utility>
class Solution {
    constexpr static unsigned long long int MOD{1'000'000'007};
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        if (n <= 0) {
            return 0;
        }
        std::queue<std::pair<unsigned long long int, int>> sq, fq;      
        sq.push(std::pair<unsigned long long int, int>(1ULL, delay));
        fq.push(std::pair<unsigned long long int, int>(1ULL, forget));
        unsigned long long int canShare{0ULL};
        for (int i = 1;i < n;++i) {
            while (!sq.empty() && sq.front().second <= i) {
                canShare = (canShare + sq.front().first) % MOD;
                sq.pop();
            }
            while (!fq.empty() && fq.front().second <= i) {
                canShare = (canShare - fq.front().first + MOD) % MOD;
                fq.pop();
            }
            if (canShare > 0) {
                sq.push(std::pair<unsigned long long int, int>(canShare, i + delay));
                fq.push(std::pair<unsigned long long int, int>(canShare, i + forget));
            }
        }
        while (!sq.empty()) {
            canShare = (canShare + sq.front().first) % MOD;
            sq.pop();
        }
        return static_cast<int>(canShare);
    }
};