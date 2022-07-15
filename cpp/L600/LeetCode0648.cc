#include <string>
using std::string;

#include <vector>
using std::vector;

#include <memory>
#include <array>

struct TireNode {
    bool leaf;
    std::array<std::shared_ptr<TireNode>, 26> nexts{{nullptr}};
};

class Solution {
private:
    std::shared_ptr<TireNode> root;

    void addWord(string const &word) {
        if (word.empty()) {
            return;
        }
        std::shared_ptr<TireNode> node = root;
        for (char const c : word) {
            int idx = c - 'a';
            if (node->nexts[idx] == nullptr) {
                node->nexts[idx] = std::make_shared<TireNode>();
            }
            node = node->nexts[idx];
        }
        node->leaf = true;
    }

    string findPrefix(string const &word) {
        if (word.empty()) {
            return word;
        }
        std::shared_ptr<TireNode> node = root;
        string res;
        for (char const c : word) {
            int idx = c - 'a';
            if (node->nexts[idx] == nullptr) {
                return word;
            }
            node = node->nexts[idx];
            res.push_back(c);
            if (node != nullptr && node->leaf) {
                break;
            }
        }
        return res;
    }
public:
    Solution(): root(std::make_shared<TireNode>()) {}
    string replaceWords(vector<string>& dictionary, string sentence) {
        for (string const &word : dictionary) {
            addWord(word);
        }
        string res;
        string word;
        std::size_t sz{sentence.size()};
        for (std::size_t i{0};i <= sz;++i) {
            if (i == sz || sentence[i] == ' ') {
                res.append(findPrefix(word));
                word = "";
                if (i < sz) {
                    res.push_back(' ');
                }
            } else {
                word.push_back(sentence[i]);
            }
        }
        return res;
    }
};