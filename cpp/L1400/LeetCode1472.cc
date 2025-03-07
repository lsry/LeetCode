#include <string>
#include <vector>
using std::string;

class BrowserHistory {
    std::vector<string> urls;
    int length;
    int cur;
public:
    BrowserHistory(string homepage): length(0), cur(0) {
        urls.emplace_back(homepage);
        length++;
    }
    
    void visit(string url) {
        if (cur + 1 == urls.size()) {
            urls.emplace_back(url);
        } else {
            urls[cur + 1] = url;
        }
        ++cur;
        length = cur + 1;
    }
    
    string back(int steps) {
        cur = cur - steps >= 0 ? cur - steps : 0;
        return urls[cur];
    }
    
    string forward(int steps) {
        cur = cur + steps < length ? cur + steps : length - 1;
        return urls[cur];
    }
};