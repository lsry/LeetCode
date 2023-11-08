#include <vector>
using std::vector;

struct Node {
    Node *left, *right;

    Node() :left(nullptr), right(nullptr) {}
};

class Solution {
    constexpr static int BITS{30};

    Node *root;

    void addNode(int num) {
        Node *cur{root};
        for (int i = BITS;i >= 0;--i) {
            if (((num >> i) & 1) == 1) {
                if (cur->right == nullptr) {
                    cur->right = new Node();
                }
                cur = cur->right;
            } else {
                if (cur->left == nullptr) {
                    cur->left = new Node();
                }
                cur = cur->left;
            }
        }
    }

    int maxXOR(int num) {
        Node *cur{root};
        int ans{0};
        for (int i = BITS;i >= 0 && cur != nullptr;--i) {
            if (((num >> i) & 1) == 1) {
                if (cur->left != nullptr) {
                    cur = cur->left;
                    ans = ans * 2 + 1;
                } else {
                    cur = cur->right;
                    ans *= 2;
                }
            } else {
                if (cur->right != nullptr) {
                    cur = cur->right;
                    ans = ans * 2 + 1;
                } else {
                    cur = cur->left;
                    ans *= 2;
                }
            }
        }
        return ans;
    }
public:
    Solution() :root(new Node()) {}

    int findMaximumXOR(vector<int>& nums) {
        int ans{0};
        for (int num : nums) {
            addNode(num);
            ans = std::max(ans, maxXOR(num));
        }
        return ans;
    }
};