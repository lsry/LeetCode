#include <vector>
using std::vector;
#include <string>
using std::string;

class Solution {
    int r, c;
    char getNextIndex(vector<string>& source) {
        c = c + 1;
        if (c >= source[r].size()) {
            r = r + 1;
            c = -1;
            return r >= source.size() ? '\r' : '\n';
        }
        return source[r][c];
    }

    void findend(vector<string>& source) {
        int state{0};
        while (true) {
            char ch = getNextIndex(source);
            if (ch == '*') {
               state = 1;
            } else if (ch == '/' && state == 1) {
                break;
            } else {
                state = 0;
            }
        }
    }
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> res;
        string line;
        r = 0, c = -1;
        while (true) {
            char ch = getNextIndex(source);
            if (ch == '\r') {
                break;
            }
            if (ch == '\n') {
                if (!line.empty()) {
                    res.push_back(line);
                    line.clear();
                }
                continue;
            } else if (ch == '/') {
                char ch2 = getNextIndex(source);
                if (ch2 == '\r') {
                    line.push_back('/');
                    break;
                } else if (ch2 == '/') {
                    c = source[r].size();
                } else if (ch2 == '*') {
                    findend(source);
                } else {
                    line.push_back('/');
                    if (ch2 == '\n') {
                        if (!line.empty()) {
                            res.push_back(line);
                            line.clear();
                        }
                    } else {
                        line.push_back(ch2);
                    }
                }
            } else {
                line.push_back(ch);
            }
        }
        if (!line.empty()) {
            res.push_back(line);
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<string> vs{"struct Node{", "    /*/ declare members;/**/", "    int size;", "    /**/int val;", "};"};
    s.removeComments(vs);
    return 0;
}
