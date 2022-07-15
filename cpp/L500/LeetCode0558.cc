#include <vector>

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if (quadTree1->isLeaf && quadTree2->isLeaf) {
            return new Node(quadTree1->val || quadTree2->val, true);
        } 
        Node *topLeft = nullptr;
        Node *topRight = nullptr;
        Node *botLeft = nullptr;
        Node *botRight = nullptr;
        if (quadTree1->isLeaf && !quadTree2->isLeaf) {
            topLeft = intersect(quadTree1, quadTree2->topLeft);
            topRight = intersect(quadTree1, quadTree2->topRight);
            botLeft = intersect(quadTree1, quadTree2->bottomLeft);
            botRight = intersect(quadTree1, quadTree2->bottomRight);
        } else if (!quadTree1->isLeaf && quadTree2->isLeaf) {
            topLeft = intersect(quadTree1->topLeft, quadTree2);
            topRight = intersect(quadTree1->topRight, quadTree2);
            botLeft = intersect(quadTree1->bottomLeft, quadTree2);
            botRight = intersect(quadTree1->bottomRight, quadTree2);
        } else {
            topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
            topRight = intersect(quadTree1->topRight, quadTree2->topRight);
            botLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
            botRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
        }
        if (topLeft->isLeaf && topRight->isLeaf && botLeft->isLeaf && botRight->isLeaf
            && topLeft->val == topRight->val && botLeft->val == botRight->val
            && topLeft->val == botLeft->val) {
            return new Node(topLeft->val, true);
        } else {
            Node *node = new Node(0, false);
            node->topLeft = topLeft;
            node->topRight = topRight;
            node->bottomLeft = botLeft;
            node->bottomRight = botRight;
            return node;
        }
    }
};