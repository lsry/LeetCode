#include <vector>
using std::vector;

#include <string>
using std::string;

class OrderedStream {
private:
    int ptr;
    vector<string> strs;
    int maxIndex;
public:
    OrderedStream(int n): ptr(1), strs(n + 1), maxIndex(n) {}
    
    vector<string> insert(int idKey, string value) {
        strs[idKey] = value;
        vector<string> res;
        if (idKey == ptr) {
            for (; ptr <= maxIndex && !strs[ptr].empty();++ptr) {
                res.push_back(strs[ptr]);
            }
        }
        return res;
    }
};