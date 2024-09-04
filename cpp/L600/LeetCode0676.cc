#include <vector>
using std::vector;

#include <string>
using std::string;

#include <memory>
#include <array>

struct TireNode
{
    std::array<std::shared_ptr<TireNode>, 26> nexts;
    bool leaf;
};

class MagicDictionary {
private:
    std::shared_ptr<TireNode> root;

    void insertWord(std::string const &str) {
        std::shared_ptr<TireNode> node = root;
        for (char const c : str) {
            int idx = c - 'a';
            if (node->nexts[idx] == nullptr) {
                node->nexts[idx] = std::make_shared<TireNode>();
            }
            node = node->nexts[idx];
        }
        node->leaf = true;
    }

    bool findWordTail(string const &word, std::size_t ix, std::shared_ptr<TireNode> node) {
        std::size_t wz{word.size()};
        for (std::size_t i{ix};i < wz;++i) {
            int idx = word[i] - 'a';
            if (node->nexts[idx] == nullptr) {
                return false;
            }
            node = node->nexts[idx];
        }
        return node != nullptr && node->leaf;
    }

    bool findWord(string const &word, std::size_t ix) {
        std::size_t wz{word.size()};
        std::shared_ptr<TireNode> node = root;
        for (std::size_t i{0};i < wz;++i) {
            int idx = word[i] - 'a';
            if (i == ix) {
                for (int j = 0;j < 26;++j) {
                    if (j == idx || node->nexts[j] == nullptr) {
                        continue;
                    }
                    if (findWordTail(word, i + 1, node->nexts[j])) {
                        return true;
                    }
                }
                return false;
            } else if (node->nexts[idx] == nullptr) {
                return false;
            }
            node = node->nexts[idx];
        }
        return node != nullptr && node->leaf;
    }
public:
    MagicDictionary(): root(std::make_shared<TireNode>()) {}
    
    void buildDict(vector<string> dictionary) {
        for (string const &word : dictionary) {
            insertWord(word);
        }
    }
    
    bool search(string searchWord) {
        std::size_t ix{searchWord.size()};
        for (std::size_t i{0};i < ix;++i) {
            // 尝试每一个可能替换字母的位置
            if (findWord(searchWord, i)) {
                return true;
            }
        }
        return false;
    }
};