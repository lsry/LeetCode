#include <fast_io.h>
#include <vector>

// plain binary search to get index where vi[index] == value or -1
int binarySearch(std::vector<int> const &vi, int value) {
    int fi = 0, ei = vi.size();
    while (fi < ei) {
        int mi = fi + (ei - fi) / 2;
        if (vi[mi] == value) {
            return mi;
        } else if (vi[mi] > value) {
            ei = mi;
        } else {
            fi = mi + 1;
        }
    }
    return -1;
}

// search leftmost index for vi[index] >= value
int binarySearchForEqualGreater(std::vector<int> const &vi, int value) {
    int fi = 0, ei = vi.size();
    while (fi < ei) {
        int mi = fi + (ei - fi) / 2;
        if (vi[mi] >= value) {
            ei = mi;
        } else {
            fi = mi + 1;
        }
    }
    return ei;
}

// search rightmost index for vi[index] <= value
int binarySearchForLessEqual(std::vector<int> const &vi, int value) {
    int fi = 0, ei = vi.size();
    while (fi < ei) {
        int mi = fi + (ei - fi) / 2;
        if (vi[mi] > value) {
            ei = mi;
        } else {
            fi = mi + 1;
        }
    }
    return fi - 1;
}

int main(int argc, char const *argv[])
{
    std::vector<int> vi{1,3,5,7,9,11,13,15};
    println("equal:\nfind 0: ", binarySearch(vi, 0));
    println("find 3: ", binarySearch(vi, 3));
    println("find 4: ", binarySearch(vi, 4));
    println("find 16: ", binarySearch(vi, 16));

    println("gerater equal:\nfind 0: ", binarySearchForEqualGreater(vi, 0));
    println("find 3: ", binarySearchForEqualGreater(vi, 3));
    println("find 4: ", binarySearchForEqualGreater(vi, 4));
    println("find 16: ", binarySearchForEqualGreater(vi, 16));

    println("Less equal:\nfind 0: ", binarySearchForLessEqual(vi, 0));
    println("find 3: ", binarySearchForLessEqual(vi, 3));
    println("find 4: ", binarySearchForLessEqual(vi, 4));
    println("find 16: ", binarySearchForLessEqual(vi, 16));
    return 0;
}

