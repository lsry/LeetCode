#include <iostream>
using std::cin;
using std::cout;

#include <unordered_map>
using std::unordered_map;

#include <string>
using std::string;

#include <memory>
using std::shared_ptr;

class Node
{
public:
    shared_ptr<Node> next, prev;
    int count;
    string val;
    Node(string s, int count = 1): val(s), count(count), prev(nullptr), next(nullptr) {};
    ~Node() {}
};

class AllOne {
private:
    unordered_map<string, shared_ptr<Node>> map;
    shared_ptr<Node> head;
public:
    AllOne() {
        head = std::make_shared<Node>("head");
        head->next = head;
        head->prev = head;
    }
    
    void inc(string key) {
        if (map.find(key) != map.end()) {
            shared_ptr<Node> node = map[key];
            node->count += 1;
            shared_ptr<Node> next = node->next;
            node->prev->next = next;
            next->prev = node->prev;
            while (next != head && next->count < node->count) {
                next = next->next;
            }
            next->prev->next = node;
            node->prev = next->prev;
            next->prev = node;
            node->next = next;
        } else {
            shared_ptr<Node> node = std::make_shared<Node>(key);
            head->next->prev = node;
            node->next = head->next;
            head->next = node;
            node->prev = head;
            map[key] = node;
        }
    }
    
    void dec(string key) {
        if (map.find(key) == map.end()) {
            return;
        }
        shared_ptr<Node> node = map[key];
        node->count -= 1;
        shared_ptr<Node> prev = node->prev;
        prev->next = node->next;
        node->next->prev = prev;
        if (node->count == 0) {
            map.erase(key);
        } else {
            while (prev != head && prev->count > node->count) {
                prev = prev->prev;
            }
            prev->next->prev = node;
            node->next = prev->next;
            prev->next = node;
            node->prev = prev;
        }
    }
    
    string getMaxKey() {
        if (head->prev == head) {
            return "";
        } else {
            return head->prev->val;
        }
    }
    
    string getMinKey() {
        if (head->next != head) {
            return head->next->val;
        } else {
            return "";
        }
    }
};

int main() {
    shared_ptr<int> p = std::make_shared<int>(34);
    cout << *p << std::endl;
    shared_ptr<string> s = std::make_shared<string>("ccccc");
    cout << s->size() << std::endl;
    std::shared_ptr<Node> node = std::make_shared<Node>("count", 1);
    cout << node->val;
    AllOne allOne;
    allOne.inc("hello");
    allOne.inc("hello");
    std::cout<<allOne.getMaxKey();
    return 0;
}
