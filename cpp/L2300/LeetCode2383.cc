#include <vector>
using std::vector;

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        std::size_t n{energy.size()};
        int d{0};
        for (std::size_t i{0};i < n;++i) {
            if (initialEnergy <= energy[i]) {
                d += energy[i] - initialEnergy + 1;
                initialEnergy = energy[i] + 1;
            }
            if (initialExperience <= experience[i]) {
                d += experience[i] - initialExperience + 1;
                initialExperience = experience[i] + 1;
            }
            initialEnergy -= energy[i];
            initialExperience += experience[i];
        }
        return d;
    }
};