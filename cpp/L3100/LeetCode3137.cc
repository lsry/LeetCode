#include <string>
#include <unordered_map>
using std::string;

class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        std::unordered_map<string, int> freqs;
        int N = word.size();
        for (int i = 0;i < N;i += k) {
            freqs[word.substr(i, k)] += 1;
        }
        int ans{N};
        for (auto const &[str, count] : freqs) {
            ans = std::min(ans, N / k - count);
        }
        return ans;
    }
};