#include <vector>
using std::vector;
#include <algorithm>
#include <numeric>
#include <memory>

class Solution;

class DataNode
{
    friend class Solution;
private:
    int one, size;
    bool reverse;  // 惰性标记
    std::shared_ptr<DataNode> left, right;
public:
    DataNode(int one, int size, bool reverse): 
          one(one), size(size), reverse(reverse), left(nullptr), right(nullptr) {}
    ~DataNode() = default;

    int getOneCount() const {
        return reverse ? size - one : one;
    }
 };

class Solution {
    std::shared_ptr<DataNode> root;

    void pushUp(std::shared_ptr<DataNode> &node) {
        if (node->left != nullptr && node->right != nullptr) {
            node->one = node->left->getOneCount() + node->right->getOneCount();
            node->size = node->left->size + node->right->size;
        } else if (node->right != nullptr) {
            node->one = node->right->getOneCount();
            node->size = node->right->size;
        } else if (node->left != nullptr) {
            node->one = node->left->getOneCount();
            node->size = node->left->size;
        }
        
    }

    std::shared_ptr<DataNode> build(vector<int>& nums, int left, int right) {
        if (right < left) {
            return nullptr;
        }
        std::shared_ptr<DataNode> node = std::make_shared<DataNode>(0, 0, false);
        if (left == right) {
            node->one = nums[left] == 0 ? 0 : 1;
            node->size = 1;
            return node;
        }
        int mid = (left + right) / 2;
        node->left = build(nums, left, mid);
        node->right = build(nums, mid + 1, right); 
        pushUp(node);
        return node;
    }

    /**
     * 下推惰性标记
     */
    void pushDown(std::shared_ptr<DataNode> &node) {
        if (!node->reverse) {
            return;
        }
        // 保证每个子节点都能获得增量
        node->reverse = false;
        if (node->left == nullptr && node->right == nullptr) {
            return;
        }
        if (node->left == nullptr) {
            node->right->reverse = !node->right->reverse;
            node->one = node->right->getOneCount();
        } else if (node->right == nullptr) {
            node->left->reverse = !node->left->reverse;
            node->one = node->left->getOneCount();
        } else {
            node->right->reverse = !node->right->reverse;
            node->left->reverse = !node->left->reverse;
            node->one = node->left->getOneCount() + node->right->getOneCount();
        }
    }

    void update(std::shared_ptr<DataNode> &node, int start, int end, int left, int right) {
        if (left <= start && end <= right) {
            node->reverse = !node->reverse;
            return;
        }
        int mid = (start + end) / 2;
        pushDown(node);
        if (left <= mid && node->left != nullptr) {
            update(node->left, start, mid, left, right);
        }
        if (right > mid && node->right != nullptr) {
            update(node->right, mid + 1, end, left, right);
        }
        pushUp(node);
    }

    int query(std::shared_ptr<DataNode> &node, int start, int end, int left, int right) {
        if (left <= start && end <= right) {
            return node->getOneCount();
        }
        int mid = (start + end) / 2, ans = 0;
        pushDown(node);
        if (left <= mid) {
            ans += query(node->left, start, mid, left, right);
        }
        if (right > mid) {
            ans += query(node->right, mid + 1, end, left, right);
        }
        return ans;
    }
public:
    Solution(): root(nullptr) {}
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        long long sum2{std::accumulate(nums2.begin(), nums2.end(), 0LL)};
        root = build(nums1, 0, nums1.size() - 1);
        vector<long long> r;
        for (vector<int> const q : queries) {
            if (q[0] == 1) {
                update(root, 0, nums1.size() - 1, q[1], q[2]);
            } else if (q[0] == 2) {
                sum2 += static_cast<long long>(query(root, 0, nums1.size() - 1, 0, nums1.size() - 1)) * q[1];
            } else if (q[0] == 3) {
                r.push_back(sum2);
            }
        }
        return r;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> n1{1,0,1}, n2{0,0,0};
    vector<vector<int>> q{{1,1,1}, {2,1,0}, {3, 0, 0}};
    s.handleQuery(n1, n2, q);
    return 0;
}
