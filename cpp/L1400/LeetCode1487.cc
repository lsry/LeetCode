#include <unordered_map>
#include <vector>
using std::vector;
#include <string>
using std::string;

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        std::unordered_map<string, int> map;
        vector<string> res;
        res.reserve(names.size());
        for (string const &name : names) {
            int left = name.size() - 1;
            auto it{map.find(name)};
            if (it == map.end()) {
                res.push_back(name);
                map[name] = 0;
            } else {
                for (int i = it->second + 1;;++i) {
                    string new_name = name + "(" + std::to_string(i) + ")";
                    if (map.find(new_name) == map.end()) {
                        res.push_back(new_name);
                        map[new_name] = 0;
                        map[name] = i;
                        break;
                    }
                }
            }
        }
        return res;
    }
};