#include <queue>
#include <vector>
using std::vector;

class LockingTree {
    vector<int> &parent;
    vector<int> locks;
    vector<vector<int>> children;
public:
    LockingTree(vector<int>& parent)
       :parent(parent), locks(parent.size(), -1), children(parent.size(), vector<int>()) {
        for (int i = 0;i < parent.size();++i) {
            if (parent[i] == -1) {
                continue;
            }
            children[parent[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if (locks[num] != -1) {
            return false;
        }
        locks[num] = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if (locks[num] == -1 || locks[num] != user) {
            return false;
        }
        locks[num] = -1;
        return true;
    }
    
    bool upgrade(int num, int user) {
        if (locks[num] != -1) {
            return false;
        }
        int pid = parent[num];
        while (pid != -1) {
            if (locks[pid] != -1) {
                return false;
            }
            pid = parent[pid];
        }
        std::queue<int> q;
        for (int id : children[num]) {
            q.push(id);
        }
        bool locksChildren{false};
        while (!q.empty()) {
            int id = q.front();
            q.pop();
            if (locks[id] != -1) {
               locksChildren = true;
               locks[id] = -1;
            }
            for (int nid : children[id]) {
                q.push(nid);
            }
        }
        if (!locksChildren) {
            return false;
        }
        locks[num] = user;
        return true;
    }
};

int main() {
    vector<int> ps{-1, 0, 0, 1, 1, 2, 2};
    LockingTree lockingTree(ps);
    lockingTree.lock(2, 2);    // 返回 true ，因为节点 2 未上锁。
                           // 节点 2 被用户 2 上锁。
    lockingTree.unlock(2, 3);  // 返回 false ，因为用户 3 无法解锁被用户 2 上锁的节点。
    lockingTree.unlock(2, 2);  // 返回 true ，因为节点 2 之前被用户 2 上锁。
                            // 节点 2 现在变为未上锁状态。
    lockingTree.lock(4, 5);    // 返回 true ，因为节点 4 未上锁。
                            // 节点 4 被用户 5 上锁。
    lockingTree.upgrade(0, 1); // 返回 true ，因为节点 0 未上锁且至少有一个被上锁的子孙节点（节点 4）。
                            // 节点 0 被用户 1 上锁，节点 4 变为未上锁。
    lockingTree.lock(0, 1);   
    return 0;
}