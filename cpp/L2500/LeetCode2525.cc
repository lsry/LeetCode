#include <string>
using std::string;

class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        unsigned long long int volumn = static_cast<unsigned long long int>(length) * width * height;
        bool larger = length >= 10000 || width >= 10000 || height >= 10000;
        bool vflag = volumn >= 1'000'000'000ULL;
        bool bulk = vflag || larger;      
        bool heavy = mass >= 100;
        if (bulk && heavy) {
            return "Both";
        } else if (bulk) {
            return "Bulky";
        } else if (heavy) {
            return "Heavy";
        } else {
            return "Neither";
        }
    }
};