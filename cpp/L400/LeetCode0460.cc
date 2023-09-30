#include <unordered_map>
#include <unordered_set>

struct Node {
    int key, value, cnt;
    Node *prev, *next;

    Node(int key, int value, int cnt, Node *prev, Node *next):
        key(key), value(value), cnt(cnt), prev(prev), next(next) {}
};

class LFUCache {
    int cap, used;
    std::unordered_map<int, Node*> datas;
    std::unordered_map<int, Node*> freqs; // 存储循环双链表, 对应结点代表最新插入的结点
    int minCnt;

    void removeFromList(Node *cur, int oldCnt) {
        if (cur->next == cur) {
            freqs[oldCnt] = nullptr;
            if (minCnt == oldCnt) {
                ++minCnt;
            }
        } else {
            Node *next = cur->next;
            next->prev = cur->prev;
            cur->prev->next = next;
            if (freqs[oldCnt] == cur) {
                freqs[oldCnt] = next;
            }
        }
    }

    void pushHead(Node *cur, int newCnt) {
        Node *next = freqs[newCnt];
        if (next == nullptr) {
            cur->next = cur;
            cur->prev = cur;
        } else {
            cur->next = next;
            cur->prev = next->prev;
            next->prev->next = cur;
            next->prev = cur;
        }
        freqs[newCnt] = cur;
    }

    void removeLFU() {
        while (freqs[minCnt] == nullptr) {
            ++minCnt;
        }
        Node *head = freqs[minCnt];
        if (head->prev == head) {
            freqs[minCnt] = nullptr;
            ++minCnt;
            datas.erase(head->key);
            delete head;
        } else {
            Node *prev = head->prev;
            prev->prev->next = head;
            head->prev = prev->prev;
            datas.erase(prev->key);
            delete prev;
        }
        --used;
    }
public:
    LFUCache(int capacity): cap(capacity), used(0), minCnt(1) {
    }
    
    int get(int key) {
        auto it{datas.find(key)};
        if (it == datas.end()) {
            return -1;
        }
        Node *cur = it->second;
        removeFromList(cur, cur->cnt);
        cur->cnt += 1;
        pushHead(cur, cur->cnt);
        return cur->value;
    }
    
    void put(int key, int value) {
        auto it{datas.find(key)};
        if (it == datas.end()) {
            if (cap == 0) {
                return;
            }
            Node *cur = new Node(key, value, 1, nullptr, nullptr);
            if (used + 1 > cap) {
                removeLFU();
            }
            pushHead(cur, cur->cnt);
            if (minCnt > cur->cnt) {
                minCnt = cur->cnt;
            }
            datas[key] = cur;
            ++used;
        } else {
            Node *cur = it->second;
            removeFromList(cur, cur->cnt);
            cur->cnt += 1;
            cur->value = value;
            pushHead(cur, cur->cnt);
        }
    }
};

int main() {
    LFUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cache.get(1);
    cache.put(3, 3);
    cache.get(2);
    cache.get(3);
    cache.put(4, 4);
    cache.get(1);
    cache.get(3);
    cache.get(4);
}