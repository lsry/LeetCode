#include <vector>
using std::vector;

#include <string>
using std::string;

#include <memory>
using std::shared_ptr;

#include <array>
using std::array;

#include <iostream>
using std::cout;
using std::endl;

#include <algorithm>

class TireNode
{   
public:
    array<shared_ptr<TireNode>, 26> leaves;  
    bool stop;
    TireNode() : stop(false) {
        leaves.fill(nullptr);
    };
    ~TireNode() {}
};


class Solution {
private:
    shared_ptr<TireNode> root;

    bool addToTire(const string &str) {
        shared_ptr<TireNode> cur = root;
        int size = str.size();
        for (int i = 0;i < size - 1;++i) {
            int id = str[i] - 'a';
            if (cur->leaves[id] == nullptr || !cur->leaves[id]->stop) {
                return false;
            }
            cur = cur->leaves[id];
        }
        int id = (int)str[size - 1] - (int)'a';
        if (cur->leaves[id] == nullptr) {
            cur->leaves[id] = std::make_shared<TireNode>();
        }
        cur->leaves[id]->stop = true;
        return true;
    }
public:
    Solution() : root(std::make_shared<TireNode>()) {}
    string longestWord(vector<string>& words) {
        stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() <= b.size();
        });
        string curStr{""};
        for (const string &word : words) {
            if (word.size() == 0) {
                continue;
            }
            if (addToTire(word)) {
                if (word.size() > curStr.size()) {
                    curStr = word;
                } else if (word.size() == curStr.size() && word < curStr) {
                    curStr = word;
                }
            }
        }
        return curStr;
    }
};

int main() {
    vector<string> vs{"ts","e","x","pbhj","opto","xhigy","erikz","pbh","opt","erikzb","eri","erik","xlye","xhig","optoj","optoje","xly","pb","xhi","x","o"};
    Solution s;
    cout << s.longestWord(vs) << endl;
}