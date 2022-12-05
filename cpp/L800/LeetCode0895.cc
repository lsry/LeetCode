#include <vector>
#include <unordered_map>
#include <queue>
#include <functional>

struct Node
{
    int value;
    int count;
    std::size_t id;

    Node(int value_, int count_, std::size_t id_): value(value_), count(count_), id(id_) {}
};


class FreqStack {
    std::unordered_map<int, int> map;
    std::function<bool(Node const &, Node const &)> cmp = [](Node const &n1, Node const &n2){
        return n1.count != n2.count ? n1.count < n2.count : n1.id < n2.id;
    };
    std::priority_queue<Node,std::vector<Node>,decltype(cmp)> pq;
    std::size_t index;
public:
    FreqStack(): pq(cmp), index(0) {}
    
    void push(int val) {
        auto n = map.find(val);
        if (n != map.end()) {
            pq.push(Node(val, n->second + 1, index));
        } else {
            pq.push(Node(val, 1, index));
        }
        map[val]++;
        ++index;
    }
    
    int pop() {
        auto p = pq.top();
        pq.pop();
        map[p.value]--;
        return p.value;
    }
};