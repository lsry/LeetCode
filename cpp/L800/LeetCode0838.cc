#include <string>
using std::string;

class Solution {
    void changeDir(string &dominoes, int left, int right) {
        int N = dominoes.size();
        if ((left - 1 < 0 && right + 1 >= N)  // ....
            || ((left - 1 < 0 || dominoes[left - 1] == 'L') && (right + 1 >= N || dominoes[right + 1] == 'R'))  // (L)...(R)
           ) {
            return;
        }
        // (L)...L
        if (right + 1 < N && dominoes[right + 1] == 'L' && (left - 1 < 0 || dominoes[left - 1] == 'L')) {
            for (int i = left;i <= right;++i) {
                dominoes[i] = 'L';
            }
        // R...(R)
        } else if (left - 1 >= 0 && dominoes[left - 1] == 'R' && (right + 1 >= N || dominoes[right + 1] == 'R')) {
            for (int i = left;i <= right;++i) {
                dominoes[i] = 'R';
            }

        // R...L
        } else {
            while (left < right) {
                dominoes[left] = 'R';
                dominoes[right] = 'L';
                ++left;
                --right;
            }
        }
    }
public:
    string pushDominoes(string dominoes) {
        int N = dominoes.size();
        for (int i = 0;i < N;++i) {
            if (dominoes[i] != '.') {
                continue;
            } else {
                int j = i + 1;
                while (j < N && dominoes[j] == '.') {
                    ++j;
                }
                changeDir(dominoes, i, j - 1);
                i = j;
            }
        }
        return dominoes;
    }
};

int main() {
    Solution s;
    s.pushDominoes(".L.R...LR..L..");
}