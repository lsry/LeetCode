#include <algorithm>
#include <stack>
#include <string>
using std::string;

class TextEditor {
    std::stack<char> leftSt, rightSt;
public:
    TextEditor() {}
    
    void addText(string text) {
        for (char c : text) {
            leftSt.push(c);
        }
    }
    
    int deleteText(int k) {
        int ans{0};
        for (;ans < k && !leftSt.empty();++ans) {
            leftSt.pop();
        }
        return ans;
    }
    
    string cursorLeft(int k) {
        for (int i = 0;i < k && !leftSt.empty();++i) {
            rightSt.push(leftSt.top());
            leftSt.pop();
        }
        string r;
        for (int i = 0;i < 10 && !leftSt.empty();++i) {
            r.push_back(leftSt.top());
            leftSt.pop();
        }
        std::reverse(r.begin(), r.end());
        for (char c : r) {
            leftSt.push(c);
        }
        return r;
    }
    
    string cursorRight(int k) {
        for (int i = 0;i < k && !rightSt.empty();++i) {
            leftSt.push(rightSt.top());
            rightSt.pop();
        }
        string r;
        for (int i = 0;i < 10 && !leftSt.empty();++i) {
            r.push_back(leftSt.top());
            leftSt.pop();
        }
        std::reverse(r.begin(), r.end());
        for (char c : r) {
            leftSt.push(c);
        }
        return r;
    }
};

int main() {
    TextEditor textEditor;
    textEditor.addText("leetcode");
    textEditor.deleteText(4);
    textEditor.addText("practice");
    textEditor.cursorRight(3);
    textEditor.cursorLeft(8);
    textEditor.deleteText(10);
    textEditor.cursorLeft(2);
    textEditor.cursorRight(6);
}