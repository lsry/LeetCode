#include <string>
using std::string;

class Solution {

    int validatePreOrder(string const &preorder, int index) {
        int N = preorder.size();
        if (index >= N) {
            return -1;
        }
        if (preorder[index] == '#') {
            return index + 1 < N ? index + 2 : index + 1;
        }
        while (index < N && preorder[index] != ',') {
            ++index;
        }
        if (index == N || index + 1 == N) {
            return -1;
        }
        int lx = validatePreOrder(preorder, index + 1);
        if (lx == -1 || lx == N) {
            return -1;
        }
        return validatePreOrder(preorder, lx);
    }
public:
    bool isValidSerialization(string preorder) {
        int x = validatePreOrder(preorder, 0);
        return x == preorder.size();
    }
};