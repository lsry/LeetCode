#include <vector>
using std::vector;

class Solution {
    int matchPixel(vector<vector<int>> const &img1, vector<vector<int>> const &img2) {
        int N = img1.size();
        int count{0};
        for (int i = 0;i < N;++i) {
            for (int j = 0;j < N;++j) {
                if (img1[i][j] == 1 && img2[i][j] == 1) {
                    ++count;
                }
            }
        }
        return count;
    }

    vector<vector<int>> moveBottom(vector<vector<int>> const &img, int step) {
        int N = img.size();
        vector<vector<int>> rimg(N, vector<int>(N, 0));
        for (int r = N - 1;r - step >= 0;--r) {
            for (int j = 0;j < N;++j) {
                rimg[r][j] = img[r - step][j];
            }
        }
        return rimg;
    }

    void moveRight(vector<vector<int>> &img, int step) {
        int N = img.size();
        for (int c = N - 1;c > 0;--c) {
            for (int r = 0;r < N;++r) {
                img[r][c] = img[r][c - 1];
            }
        }
        for (int r = 0;r < N;++r) {
            img[r][0] = 0;
        }
    }

    int maxMatchPixel(vector<vector<int>> &img1, vector<vector<int>> &img2) {
        int ans{0};
        int N = img1.size();
        for (int mb{0};mb < N;++mb) {
            vector<vector<int>> rimg{moveBottom(img1, mb)};
            for (int mr{0};mr < N;++mr) {
                if (mr > 0) {
                    moveRight(rimg, 1);
                }
                int count = matchPixel(rimg, img2);
                ans = std::max(count, ans);
            }
        }
        return ans;
    }
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        return std::max(maxMatchPixel(img1, img2), maxMatchPixel(img2, img1));
    }
};
