#include <memory>

class TimeNode {
public:
    int start, end;
    std::shared_ptr<TimeNode> next;
    TimeNode(int _start, int _end) : start(_start), end(_end), next(nullptr) {}
};

class MyCalendar {
private:
    std::shared_ptr<TimeNode> root;
public:
    MyCalendar(): root(std::make_shared<TimeNode>(0, 0)) {}
    
    bool book(int start, int end) {
        bool insert{true};
        std::shared_ptr<TimeNode> node = root;
        while (node->next != nullptr) {
            if (node->next->end <= start) {
                node = node->next;
            } else if (end <= node->next->start) {
                break;
            } else {
                insert = false;
                break;
            }
        }
        if (insert) {
            std::shared_ptr<TimeNode> n = std::make_shared<TimeNode>(start, end);
            n->next = node->next;
            node->next = n;
        }
        return insert;
    }
};