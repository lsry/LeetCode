#include <cctype>
#include <string>
using std::string;

class Solution {
    void to_lower_str(string &str, std::size_t low, std::size_t high) {
        for (std::size_t i{low};i < high;++i) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                str[i] = std::tolower(str[i]);
            }
        }
    }
public:
    string capitalizeTitle(string title) {
        std::size_t tz{title.size()};
        for (std::size_t i{0};i < tz;) {
            if (title[i] == ' ') {
                ++i;
                continue;
            }
            std::size_t j{i};
            while (j < tz && title[j] != ' ') {
                ++j;
            }
            to_lower_str(title, i, j);
            if (j - i >= 3) {
                title[i] = std::toupper(title[i]);
            }
            i = j + 1;
        }
        return title;
    }
};