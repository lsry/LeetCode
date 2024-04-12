#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using std::vector;
using std::string;

struct People {
    string name;
    std::vector<People*> children;
    bool dead;
    People(string name): name(std::move(name)), dead(false) {}
};

class ThroneInheritance {
    People *root;
    std::unordered_map<string, People*> names;

    void dfs(People *node, vector<string> &orders) {
        if (node == nullptr) {
            return;
        }
        if (!node->dead) {
            orders.push_back(node->name);
        }
        for (People *c : node->children) {
            dfs(c, orders);
        }
    }
public:
    ThroneInheritance(string kingName) {
        root = new People(kingName);
        names[kingName] = root;
    }
    
    void birth(string parentName, string childName) {
        People *parent = names[parentName];
        if (parent != nullptr) {
            People* child = new People(childName);
            parent->children.push_back(child);
            names[childName] = child;
        }
    }
    
    void death(string name) {
        People *p = names[name];
        if (p != nullptr) {
            p->dead = true;
        }
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> res;
        dfs(root, res);
        return res;
    }
};