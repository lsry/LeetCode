#include <vector>
using std::vector;
#include <string>
using std::string;
#include <unordered_map>
#include <algorithm>
#include <memory>

struct Node {
    string fname;
    bool leaf;
    
    std::unordered_map<string, std::shared_ptr<Node>> map;

    Node() {}

    Node(string const &fn): fname(fn), leaf(false) {}
};


class Solution {
    void splitFolde(string const &f, vector<string> &fs) {
        std::size_t fz{f.size()};
        for (std::size_t i{0};i < fz;++i) {
            if (f[i] == '/') {
                continue;
            }
            std::size_t j{i};
            while (j < fz && f[j] != '/') {
                ++j;
            }
            fs.push_back(f.substr(i, j - i));
            i = j;
        }
    }
    bool find(std::shared_ptr<Node> head, std::vector<string> &fs) {
        std::shared_ptr<Node> cur{head};
        for (string const &fname : fs) {
            if (cur == nullptr) {
                return false;
            }
            auto it{cur->map.find(fname)};
            if (it == cur->map.end() || it->second == nullptr) {
                return false;
            }
            if (it->second->leaf) {
                return true;
            }
            cur = it->second;
        }
        return false;
    }
    void insert(std::shared_ptr<Node> head, std::vector<string> &fs) {
        std::shared_ptr<Node> cur{head};
        for (string const &fname : fs) {
            auto it{cur->map.find(fname)};
            if (it == cur->map.end()) {
                cur->map[fname] = std::make_shared<Node>(fname);
            }
            cur = cur->map[fname];
        }
        cur->leaf = true;
    }
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        std::stable_sort(folder.begin(), folder.end(), [](auto const &f1, auto const &f2) {
            return f1.size() <= f2.size();
        });
        vector<string> res;
        std::shared_ptr<Node> head{std::make_shared<Node>()};
        for (string const &f : folder) {
            vector<string> fs;
            splitFolde(f, fs);
            if (find(head, fs)) {
                continue;
            }
            res.push_back(f);
            insert(head, fs);
        }
        return res;
    }
};