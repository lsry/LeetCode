#include <vector>
using std::vector;

#include <string>
using std::string;

#include <memory>
#include <array>    

struct TrieNode
{
    std::array<std::shared_ptr<TrieNode>, 26> nexts;
    vector<int> preIds;
    vector<int> sufIds;
};


class WordFilter {
private:
    std::shared_ptr<TrieNode> root;

    void addWord(string const &word, int id) {
        std::shared_ptr<TrieNode> cur = root;
        for (char const & c : word) {
            int pos = c - 'a';
            if (cur->nexts[pos] == nullptr) {
                cur->nexts[pos] = std::make_shared<TrieNode>();
            }
            cur = cur->nexts[pos];
            cur->preIds.push_back(id);
        }
        cur = root;
        for (int i = word.size() - 1;i >= 0;--i) {
            int pos = word[i] - 'a';
            if (cur->nexts[pos] == nullptr) {
                cur->nexts[pos] = std::make_shared<TrieNode>();
            }
            cur = cur->nexts[pos];
            cur->sufIds.push_back(id);
        }
    }

    int findId(string const &pre, string const &suf) {
        std::shared_ptr<TrieNode> cur = root;
        for (char const &c : pre) {
            int pos = c - 'a';
            if (cur->nexts[pos] == nullptr) {
                return -1;
            }
            cur = cur->nexts[pos];
        }
        vector<int> &preIds = cur->preIds;
        cur = root;
        for (int i = suf.size() - 1;i >= 0;--i) {
            int pos = suf[i] - 'a';
            if (cur->nexts[pos] == nullptr) {
                return -1;
            }
            cur = cur->nexts[pos];
        }
        vector<int> &sufIds = cur->sufIds;
        int pm = preIds.size(), sm = sufIds.size();
        for (int i = pm - 1, j = sm - 1;i >= 0 && j >= 0;) {
            if (preIds[i] > sufIds[j]) {
                --i;
            } else if (preIds[i] < sufIds[j]) {
                --j;
            } else {
                return preIds[i];
            }
        }
        return -1;
    }
public:
    WordFilter(vector<string>& words): root(std::make_shared<TrieNode>()) {
        for (int i = 0;i < words.size();++i) {
            addWord(words[i], i);
        }
    }
    
    int f(string pref, string suff) {
        return findId(pref, suff);
    }
};
