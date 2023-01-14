#include <vector>
using std::vector;
#include <memory>

struct TireNode {
    int count;
    std::unique_ptr<TireNode> left, right;

    TireNode(): count(0), left(nullptr), right(nullptr) {}
};

class Solution {
    constexpr static int HIG_BIT{14};
    void addToTree(std::unique_ptr<TireNode> &root, int num) {
        TireNode *node = root.get();
        for (int i{HIG_BIT};i >= 0;--i) {
            int r = (num >> i) & 1;
            if (r == 1) {
                if (node->right == nullptr) {
                    node->right = std::make_unique<TireNode>();
                }
                node->right->count += 1;
                node = node->right.get();
            } else {
                if (node->left == nullptr) {
                    node->left = std::make_unique<TireNode>();
                }
                node->left->count += 1;
                node = node->left.get();
            }
        }
    }
    int lowerCount(std::unique_ptr<TireNode> &root, int num, int limit) {
        TireNode *node = root.get();
        int ans{0};
        for (int i{HIG_BIT};i >= 0 && node != nullptr;--i) {
            int nr = (num >> i) & 1;
            int lr = (limit >> i) & 1;
            if (lr == 0) {
                node = nr == 0 ? node->left.get() : node->right.get();
            } else {
                if (nr == 0) {
                    if (node->left != nullptr) {
                        ans += node->left->count;
                    }
                    node = node->right.get();
                } else {
                    if (node->right != nullptr) {
                        ans += node->right->count;
                    }
                    node = node->left.get();
                }
            }
        }
        if (node != nullptr) {
            ans += node->count;
        }
        return ans;
    }
    int pairCounts(vector<int> &nums, int limit) {
        std::unique_ptr<TireNode> root{std::make_unique<TireNode>()};
        std::size_t nz{nums.size()};
        int count{0};
        for (std::size_t i{1};i < nz;++i) {
            addToTree(root, nums[i - 1]);
            count += lowerCount(root, nums[i], limit);
        }
        return count;
    }
public:
    int countPairs(vector<int>& nums, int low, int high) {
        return pairCounts(nums, high) - pairCounts(nums, low - 1);
    }
};