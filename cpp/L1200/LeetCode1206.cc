#include <memory>
#include <random>
#include <vector>

struct SkipNode
{
    int val;
    std::shared_ptr<SkipNode> prev, next, top, down;
    bool head;
    
    SkipNode(int val, bool head): val(val), prev(nullptr), next(nullptr), top(nullptr), down(nullptr), head(head) {}
};

class Skiplist {
private:
    std::default_random_engine engine;
    int level;
    constexpr static int MAX_LEVEL = 32;
    std::vector<std::shared_ptr<SkipNode>> headNodes;
public:
    Skiplist():level(-1), headNodes(MAX_LEVEL, nullptr) {}
    
    bool search(int target) {
        if (level == -1) {
            return false;
        }
        for (std::shared_ptr<SkipNode> node{headNodes[level]};node != nullptr;) {
            if (node->next == nullptr || node->next->val > target) {
                node = node->down;
            } else if (node->next->val == target) {
                return true;
            } else {
                node = node->next;
            }
        }
        return false;
    }
    
    void add(int num) {
        if (level == -1) {
            ++level;
            headNodes[level] = std::make_shared<SkipNode>(0, true);
            std::shared_ptr<SkipNode> cur = std::make_shared<SkipNode>(num, false);
            cur->prev = headNodes[level];
            headNodes[level]->next = cur;
            return;
        }
        std::vector<std::shared_ptr<SkipNode>> prevNodes;
        int iterLevel = level;
        for (std::shared_ptr<SkipNode> node{headNodes[iterLevel]};node != nullptr && iterLevel >= 0;) {
            while (node->next != nullptr && node->next->val <= num) {
                node = node->next;
            }
            prevNodes.push_back(node);
            node = node->down;
            --iterLevel;
        }
        bool up = true;
        std::shared_ptr<SkipNode> cur = std::make_shared<SkipNode>(num, false);
        for (int i = prevNodes.size() - 1;i >= 0;--i) {
            std::shared_ptr<SkipNode> node = prevNodes[i];
            cur->next = node->next;
            cur->prev = node;
            if (node->next != nullptr) {
                node->next->prev = cur;
            }
            node->next = cur;
            std::uniform_int_distribution<int> u(1, 100);
            if (u(engine) < 50) {
                up = false;
                break;
            }
            std::shared_ptr<SkipNode> topNode = std::make_shared<SkipNode>(num, false);
            cur->top = topNode;
            topNode->down = cur;
            cur = topNode;
        }
        if (up && level < MAX_LEVEL) {
            ++level;
            headNodes[level] = std::make_shared<SkipNode>(0, true);
            headNodes[level]->down = headNodes[level - 1];
            headNodes[level - 1]->top = headNodes[level];
            cur->prev = headNodes[level];
            headNodes[level]->next = cur;
        }
    }
    
    bool erase(int num) {
        if (level == -1) {
            return false;
        }
        std::shared_ptr<SkipNode> node = headNodes[level];
        int iterLevel = level;
        for (;node != nullptr;) {
            if (node->next == nullptr || node->next->val > num) {
                node = node->down;
                --iterLevel;
            } else if (node->next->val == num) {
                node = node->next;
                break;
            } else {
                node = node->next;
            }
        }
        if (node == nullptr) {
            return false;
        }
        while (node != nullptr && iterLevel >= 0) {
            if (node->prev->head && node->next == nullptr) {
                headNodes[iterLevel] = nullptr;
                node->prev = nullptr;
                --level;
            } else {
                if (node->next != nullptr) {
                    node->next->prev = node->prev;
                }
                node->prev->next = node->next;
                node->prev = nullptr;
                node->next = nullptr;
            }
            node = node->down;
            if (node != nullptr) {
                node->top = nullptr;
            }
            --iterLevel;
        }
        return true;
    }
};