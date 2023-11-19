class RangeModule;

class DataNode {
    friend class RangeModule;
    DataNode *left, *right;
    bool cover;
    int addFlag;
public:
    DataNode() : cover(false), addFlag(0), left(nullptr), right(nullptr) {}
};

class RangeModule {
    DataNode *root;
    constexpr static int N{1000000000};

    void pushDown(DataNode *node, int start, int end) {
        if (node->left == nullptr) {
            node->left = new DataNode();
        }
        if (node->right == nullptr) {
            node->right = new DataNode();
        }
        if (node->addFlag == 0) {
            return;
        }
        node->left->cover = node->addFlag == 1;
        node->right->cover = node->addFlag == 1;
        node->left->addFlag = node->addFlag;
        node->right->addFlag = node->addFlag;
        node->addFlag = 0;
    }

    void update(DataNode *node, int start, int end, int left, int right, int val) {
        if (left <= start && end <= right) {
            node->cover = val == 1;
            node->addFlag = val;
            return;
        }
        int mid = start + (end - start) / 2;
        pushDown(node, mid - start + 1, end - mid);
        if (left <= mid) {
            update(node->left, start, mid, left, right, val);
        }
        if (right > mid) {
            update(node->right, mid + 1, end, left, right, val);
        }
        pushUp(node);
    }

    void pushUp(DataNode *node) {
        node->cover = node->left->cover && node->right->cover;
    }

    bool query(DataNode *node, int start, int end, int left, int right) {
        if (left <= start && end <= right) {
            return node->cover;
        }
        int mid = start + (end - start) / 2;
        bool ans = true;
        pushDown(node, mid - start + 1, end - mid);
        if (left <= mid) {
            ans = ans && query(node->left, start, mid, left, right);
        }
        if (right > mid) {
            ans = ans && query(node->right, mid + 1, end, left, right);
        }
        return ans;
    }
public:
    RangeModule() : root(new DataNode()) {}
    
    void addRange(int left, int right) {
        update(root, 1, N, left, right - 1, 1);
    }
    
    bool queryRange(int left, int right) {
        return query(root, 1, N, left, right - 1);
    }
    
    void removeRange(int left, int right) { 
        update(root, 1, N, left, right - 1, -1);
    }
};