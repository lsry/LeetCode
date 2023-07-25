#include <memory>
#include <vector>

/*
 * 题型
 * 2569
 * 
 */

/**
 * 指针法构建线段树，不需要预先分配空间
 */

class LineSegmentTree;

class DataNode
{
    friend class LineSegmentTree;
private:
    int val;
    int add;  // 惰性标记
    std::shared_ptr<DataNode> left, right;
public:
    DataNode(int val, int add = 0) : val(val), add(add), left(nullptr), right(nullptr) {}
    ~DataNode() = default;
};


class LineSegmentTree {
private:
    std::shared_ptr<DataNode> root;

    void pushUp(std::shared_ptr<DataNode> &node) {
        node->val = node->left->val + node->right->val;
    }

    /**
     * 下推惰性标记
     */
    void pushDown(std::shared_ptr<DataNode> &node, int left, int right) {
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
        node->left->val += node->add * left;
        node->right->val += node->add * right;
        node->left->add = node->add;
        node->right->add = node->add;
        node->add = 0;
    }
public:
    LineSegmentTree() : root(nullptr) {}

    /**
     * 初始化直接根据区间构建一棵树
     */
    std::shared_ptr<DataNode> build(int left, int right) {
        std::shared_ptr<DataNode> node = std::make_shared<DataNode>(0);
        if (left == right) {
            node->val = left;
            return node;
        }
        int mid = (left + right) / 2;
        node->left = build(left, mid);
        node->right = build(mid + 1, right); 
        pushUp(node);
        return node;
    }

    /**
     * 更新区间值
     * 
     * [start, end]: 发现的区间 
     * [left, right]: 待更新的区间 
     */
    void update(std::shared_ptr<DataNode> &node, int start, int end, int left, int right, int val) {
        if (left <= start && end <= right) {
            node->val += (end - start + 1) * val;
            node->add = val;
            return;
        }
        int mid = (start + end) / 2;
        pushDown(node, mid - start + 1, end - mid);
        if (left <= mid) {
            update(node->left, start, mid, left, right, val);
        }
        if (right > mid) {
            update(node->right, mid + 1, end, left, right, val);
        }
        pushUp(node);
    }

    int query(std::shared_ptr<DataNode> &node, int start, int end, int left, int right) {
        if (left <= start && end <= right) {
            return node->val;
        }
        int mid = (start + end) / 2, ans = 0;
        pushDown(node, mid - start + 1, end - mid);
        if (left <= mid) {
            ans += query(node->left, start, mid, left, right);
        }
        if (right > mid) {
            ans += query(node->right, mid + 1, end, left, right);
        }
        return ans;
    }
};

/**
 * 數組法構建綫段樹
 * LeetCode1157
 */

