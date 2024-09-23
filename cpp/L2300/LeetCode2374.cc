#include <vector>
using std::vector;

class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int N = edges.size();
        vector<unsigned long long int> grades(N, 0ULL);
        int node{0};
        unsigned long long int grade{0ULL};
        for (int i = 0;i < N;++i) {
            grades[edges[i]] += i;
            if (grades[edges[i]] > grade || grades[edges[i]] == grade && edges[i] < node) {
                node = edges[i];
                grade = grades[edges[i]];
            }
        }      
        return node;
    }
};