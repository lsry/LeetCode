#include <array>
#include <string>
using std::string;
#include <memory>
#include <algorithm>
#include <vector>
using std::vector;

struct TireNode {
    std::array<std::unique_ptr<TireNode>, 26> childs;
    bool leaf;

    TireNode(): leaf(false) {
        std::fill(childs.begin(), childs.end(), nullptr);
    } 
};

class StreamChecker {
    std::unique_ptr<TireNode> root;
    string received;

    void insert(string const &word) {
        if (word.empty()) {
            return;
        }
        TireNode *node{root.get()};
        for (auto it{word.rbegin()}; it != word.rend();++it) {
            int id{*it - 'a'};
            if (node->childs[id] == nullptr) {
                node->childs[id] = std::make_unique<TireNode>();
            }
            node = node->childs[id].get();
        }
        node->leaf = true;
    }

    bool check_exist() {
        TireNode *node{root.get()};
        for (auto it{received.rbegin()}; it != received.rend();++it) {
            int id{*it - 'a'};
            if (node->childs[id] == nullptr) {
                return false;
            }
            node = node->childs[id].get();
            if (node->leaf) {
                return true;
            }
        }
        return false;
    }
public:
    StreamChecker(vector<string>& words): root(std::make_unique<TireNode>()) {
        for (string const &word : words) {
            insert(word);
        }
    }
    
    bool query(char letter) {
        received.push_back(letter);
        return check_exist();
    }
};
