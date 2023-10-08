#include "../heads/list_node.h"

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node *res = new Node(insertVal);
        res->next = res;
        if (head == nullptr) {
            return res;
        }
        Node *root = head->next;
        Node *prev = head;
        while (root != head) {
            if (prev->val > root->val) {
                break;
            }
            prev = root;
            root = root->next;
        }
        prev->next = nullptr;
        Node *cur = root;
        if (insertVal < root->val) {
            prev->next = res;
            res->next = root;
            return head;
        }
        while (cur->next != nullptr && cur->next->val < insertVal) {
            cur = cur->next;
        }
        if (cur->next == nullptr) {
            res->next = root;
            prev->next = res;
        } else {
            res->next = cur->next;
            cur->next = res;
            prev->next = root;
        }
        return head;
    }
};