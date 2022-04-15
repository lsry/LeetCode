#include <vector>
using std::vector;
#include <string>
using std::string;
#include <memory>
using std::shared_ptr;

class TireNode
{
public:
    shared_ptr<TireNode> point, cross;
    char ch;
    bool leaf;
    TireNode(char c) : ch(c), point(nullptr), cross(nullptr), leaf(false){}
    ~TireNode(){}
};


class Solution {
    vector<string> exprs{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
       "-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    shared_ptr<TireNode> root;
    int count;
    void addToTree(const string &word) {
        std::shared_ptr<TireNode> cur = root;
        for (const char ch : word) {
            string mosSign = exprs[(int)(ch - 'a')];
            for (const char mos : mosSign) {
                if (mos == '.' ) {
                    if (cur -> point == nullptr) {
                        cur->point = std::make_shared<TireNode>('.');
                    }
                    cur = cur->point;
                } else {
                    if (cur->cross == nullptr) {
                        cur->cross = std::make_shared<TireNode>('-');
                    }
                    cur = cur->cross;
                }
            }
        }
        if (cur->leaf == false) {
            cur->leaf = true;
            ++count;
        }
    }
public:
    Solution(): root(std::make_shared<TireNode>('r')), count(0){}
    int uniqueMorseRepresentations(vector<string>& words) {
        count = 0;
        for (const string &word : words) {
            addToTree(word);
        }
        return count;
    }
};