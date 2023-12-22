#include <unordered_map>
#include <vector>
using std::vector;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int M = mat.size(), N = mat[0].size();
        std::unordered_map<int, int> mp;
        for (int i = 0;i < M;++i) {
            for (int j = 0;j < N;++j) {
                mp[mat[i][j]] = i * N + j;
            }
        }      
        vector<int> row(M, 0), col(N, 0);
        for (int i = 0;i < arr.size();++i) {
            int n = mp[arr[i]];
            int r = n / N, c = n % N;
            row[r] += 1;
            col[c] += 1;
            if (row[r] == N || col[c] == M) {
                return i;
            }
        }
        return arr.size() - 1;
    }
};

int main() {
    Solution s;
    vector<int> arr{2,8,7,4,1,3,5,6,9};
    vector<vector<int>> mat{{3,2,5}, {1,4,6}, {8,7,9}};
    s.firstCompleteIndex(arr, mat);
}