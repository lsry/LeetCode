#include <vector>
using std::vector;

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
private:
    int N;
public:
    Node* construct(vector<vector<int>>& grid) {
        N = grid.size();
        if (N == 0) {
            return new Node();
        }
        return helper(grid, 0, N - 1, 0, N - 1);
    }

    Node* helper(vector<vector<int>> &grid, int left, int right, int top, int down) {
        if (left < 0 || left > right || right < left || right >= N || top < 0 || top > down || down < top || down >= N) {
            return nullptr;
        }
        bool same = isAllSame(grid, left, right, top, down);
        if (same || (left == right && top == down)) {
            return new Node(grid[top][left], true);
        }
        Node *node = new Node(false, false);
        int rmi = (right + left) / 2;
        int cmi = (down + top) / 2;
        node->topLeft = helper(grid, left, rmi , top, cmi);
        node->topRight = helper(grid, rmi + 1, right, top, cmi);
        node->bottomLeft = helper(grid, left, rmi, cmi + 1, down);
        node->bottomRight = helper(grid, rmi + 1, right, cmi + 1, down);
        return node;
    }

    bool isAllSame(vector<vector<int>> &grid, int left, int right, int top, int down) {
        int val = grid[top][left];
        for (int i = top;i <= down;++i) {
            for (int j = left;j <= right;++j) {
                if (grid[i][j] != val) {
                    return false;
                }
            }
        }
        return true;
    }
};