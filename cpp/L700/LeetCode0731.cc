#include <memory>

struct DataNode
{
    int val;
    int add;  // 惰性标记
    std::shared_ptr<DataNode> left, right;
    DataNode(int val, int add = 0) : val(val), add(add), left(nullptr), right(nullptr) {}
    ~DataNode() = default;
};

class MyCalendarTwo {
private:
    std::shared_ptr<DataNode> root;

    void pushUp(std::shared_ptr<DataNode> node) {
        node->val = std::max(node->left->val, node->right->val);
    }

    /**
     * 下推惰性标记
     */
    void pushDown(std::shared_ptr<DataNode> node) {
        if (node->left == nullptr) {
            node->left = std::make_shared<DataNode>(0);
        }
        if (node->right == nullptr) {
            node-> right = std::make_shared<DataNode>(0);
        }
        if (node->add == 0) {
            return;
        }
        // 保证每个子节点都能获得增量
        node->left->val += node->add;
        node->right->val += node->add;
        node->left->add += node->add;
        node->right->add += node->add;
        node->add = 0;
    }

    int query(std::shared_ptr<DataNode> node, int start, int end, int left, int right) {
        if (left <= start && end <= right) {
            return node->val;
        }
        int mid = (start + end) / 2;
        int ans = 0;
        pushDown(node);
        if (left <= mid) {
            ans = std::max(query(node->left, start, mid, left, right), ans);
        }
        if (right > mid) {
            ans = std::max(query(node->right, mid + 1, end, left, right), ans);
        }
        return ans;
    }

    void update(std::shared_ptr<DataNode> node, int start, int end, int left, int right, int val) {
        if (left <= start && end <= right) {
            node->val += val;
            node->add += val;
            return;
        }
        int mid = (start + end) / 2;
        pushDown(node);
        if (left <= mid) {
            update(node->left, start, mid, left, right, val);
        }
        if (right > mid) {
            update(node->right, mid + 1, end, left, right, val);
        }
        pushUp(node);
    }
public:
    MyCalendarTwo():root(std::make_shared<DataNode>(0)) {}
    
    bool book(int start, int end) {
        if (query(root, 0, (int)1e9, start, end - 1) >= 2) {
            return false;
        }
        update(root, 0, (int)1e9, start, end - 1, 1);
        return true;
    }
};