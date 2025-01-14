#include "../heads/tree_node.h"
#include "../heads/list_node.h"

class Solution {
    bool checkList(ListNode *head, TreeNode* root) {
        if (head == nullptr) {
            return true;
        }
        if (root == nullptr || head->val != root->val) {
            return false;
        }
        return checkList(head->next, root->left) || checkList(head->next, root->right);
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (head == nullptr) {
            return true;
        }
        if (root == nullptr) {
            return false;
        }
       if (checkList(head, root)) {
            return true;
       }
       return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};