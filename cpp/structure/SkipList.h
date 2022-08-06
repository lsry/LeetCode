#include <vector>
#include <memory>
#include <random>
#include <optional>

#include <iostream>

template<typename T>
struct SkipNode {
    T value;
    std::vector<std::shared_ptr<SkipNode<T>>> forwards;

    SkipNode(T t, int N) : value(t), forwards(N + 1, nullptr) {}
    SkipNode(int N): forwards(N + 1, nullptr) {}
};

template<typename T>
class SkipList
{
private:
    std::shared_ptr<SkipNode<T>> head;
    int level;
    constexpr static int MAX_LEVEL = 16;
    static std::default_random_engine engine;
    double rate; 

    int randomLevel() {
        std::uniform_real_distribution<double> u(0, 1);
        int curLevel = 0;
        while (u(engine) < rate && curLevel < MAX_LEVEL - 1) {
            ++curLevel;
        }
        return curLevel;
    }
public:
    SkipList(double rate_ = 0.5): level(0), rate(rate_), head(std::make_shared<SkipNode<T>>(MAX_LEVEL))  {}

    void add(T t) {
        std::vector<std::shared_ptr<SkipNode<T>>> updates(level + 1, nullptr);
        std::shared_ptr<SkipNode<T>> node = head;
        for (int i{level};i >= 0;--i) {
            while (i < node->forwards.size() && node->forwards[i] != nullptr && node->forwards[i]->value < t) {
                node = node->forwards[i];
            }
            updates[i] = node;
        }
        int curLevel = randomLevel();
        std::shared_ptr<SkipNode<T>> insertNode = std::make_shared<SkipNode<T>>(t, curLevel > level ? level + 1 : curLevel);
        for (int i{0}, j{std::min(curLevel, level)};i <= j;++i) {
            insertNode->forwards[i] = updates[i]->forwards[i];
            updates[i]->forwards[i] = insertNode;
        }
        if (curLevel > level) {
            ++level;
            head->forwards[level] = insertNode;
        }
        std::cout << "value: " << t << ", level: " << level  << ", curLevel: " << curLevel << std::endl;
    }

    bool findValue(T const &t) {
        std::shared_ptr<SkipNode<T>> node = head;
        for (int i = level;i >= 0;--i) {
            while (i < node->forwards.size() && node->forwards[i] != nullptr && node->forwards[i]->value < t) {
                node = node->forwards[i];
            }
        }
        return node->forwards[0] != nullptr && node->forwards[0]->value == t;
    }

    void eraseNode(T const &t) {
        std::shared_ptr<SkipNode<T>> node = head;
        std::vector<std::shared_ptr<SkipNode<T>>> updates(level + 1, nullptr);
        for (int i = level;i >= 0;--i) {
            while (i < node->forwards.size() && node->forwards[i] != nullptr && node->forwards[i]->value < t) {
                node = node->forwards[i];
            }
            updates[i] = node;
        }
        node = node->forwards[0];
        if (node == nullptr || node->value != t) {
            return;
        }
        for (int i = 0;i <= level;++i) {
            if (updates[i] == nullptr || updates[i]->forwards[i] == nullptr || updates[i]->forwards[i]->value != t) {
                break;
            }
            updates[i]->forwards[i] = node->forwards[i];
        }
        while (level >= 0 && head->forwards[level] == nullptr) {
            --level;
        }
        level = std::max(level, 0);
    }

    void printSkipList() {
        std::shared_ptr<SkipNode<T>> node = head;
        std::cout << "SkipList:\n";
        while (node->forwards[0] != nullptr) {
            node = node->forwards[0];
            int sz = node->forwards.size();
            for (int i{0};i < sz;++i) {
                std::cout << node->value << " ";
            }
            std::cout << std::endl;
        }
    }
};

template<typename T>
std::default_random_engine SkipList<T>::engine{};