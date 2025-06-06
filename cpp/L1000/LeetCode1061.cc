#include <array>
#include <string>
using std::string;

struct UnionFind {
    std::array<int, 26> ids;

    UnionFind() {
        for (int i = 0;i < 26;++i) {
            ids[i] = i;
        }
    }

    int toFind(int id) {
        while (ids[id] != id) {
            id = ids[id];
        }
        return id;
    }

    void to_union(int x, int y) {
        int xid = toFind(x);
        int yid = toFind(y);
        if (xid == yid) {
            return;
        }
        if (xid < yid) {
            ids[yid] = xid;
        } else {
            ids[xid] = yid;
        }
    }

    
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        UnionFind uf;
        for (int i = 0;i < s1.size();++i) {
            int x1 = s1[i] - 'a';
            int x2 = s2[i] - 'a';
            uf.to_union(x1, x2);
        }
        for (int i = 0;i < baseStr.size();++i) {
            int x = baseStr[i] - 'a';
            baseStr[i] = char('a' + uf.toFind(x));
        }
        return baseStr;
    }
};