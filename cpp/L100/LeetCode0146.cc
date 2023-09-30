#include <unordered_map>
struct Node {
    int key, value;
    Node *prev, *next;

    Node(int key, int value): key(key), value(value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
    std::unordered_map<int, Node*> map;
    Node head;
    Node *tail;
    int size, used;

    void pushTail(Node *cur) {
        tail->next = cur;
        cur->prev = tail;
        tail = cur;
    }

    void removeFirst() {
        if (head.next == nullptr) {
            return;
        }
        Node *cur = head.next;
        if (cur == nullptr) {
            return;
        }
        head.next = cur->next;
        if (cur->next != nullptr) {
            cur->next->prev = &head;
        } else {
            tail = &head;
        }
        map.erase(cur->key);
        delete cur;
        --used;
    }
public:
    LRUCache(int capacity): head(0 ,0), size(capacity), used(0) {
        tail = &head;
    }
    
    int get(int key) {
        auto it{map.find(key)};
        if (it == map.end()) {
            return -1;
        }
        Node *cur = it->second;
        if (cur != tail) {
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            pushTail(cur);
        }
        return cur->value;
    }
    
    void put(int key, int value) {
        auto it{map.find(key)};
        if (it == map.end()) {
            Node *cur = new Node(key, value);
            if (used + 1 > size) {
                removeFirst();
            }
            map[key] = cur;
            pushTail(cur);
            ++used;
        } else {
            Node *cur = it->second;
            cur->value = value;
            if (cur != tail) {
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
                pushTail(cur);
            }
        }
    }
};