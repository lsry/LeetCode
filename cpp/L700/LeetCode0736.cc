#include <string>
using std::string;

#include <unordered_map>
#include <memory>

struct Fields {
    std::unordered_map<string, int> map;
    std::shared_ptr<Fields> parent;

    Fields(): parent(nullptr) {}
};


class Solution {
private:
    std::size_t idx{0}, ez{0};
    string &expr;

    string nextToken() {
        while (idx < ez && expr[idx] == ' ') {
            ++idx;
        }
        string res;
        if (idx >= ez) {
            return res;
        }
        if (expr[idx] == '(' || expr[idx] == ')') {
            res.push_back(expr[idx]);
            ++idx;
            return res;
        }
        while (idx < ez && (expr[idx] != ' ' && expr[idx] != '(' && expr[idx] != ')')) {
            res.push_back(expr[idx]);
            ++idx;
        }
        return res;
    }

    int calcExpr(std::shared_ptr<Fields> field) {
        string token = nextToken();
        if (token.empty()) {
            return 0;
        }
        if (token == "(") {
            return bracketExpr(field);
        } else {
            return immediateExpr(token, field);
        }
    }

    int bracketExpr(std::shared_ptr<Fields> field) {
        string token = nextToken();
        if (token.empty() || token == ")") {
            return 0;
        }
        if (token == "let") {
            return letExpr(field);
        } else if (token == "add") {
            return addExpr(field);
        } else if (token == "mult") {
            return multExpr(field);
        } else {
            nextToken();
            return immediateExpr(token, field);
        }
    }

    int multExpr(std::shared_ptr<Fields> field) {
        int n1 = 0;
        string t1 = nextToken();
        if (t1 == "(") {
            n1 = bracketExpr(field);
        } else {
            n1 = immediateExpr(t1, field);
        }
        int n2 = 0;
        string t2 = nextToken();
        if (t2 == "(") {
            n2 = bracketExpr(field);
        } else {
            n2 = immediateExpr(t2, field);
        }
        nextToken();
        return n1 * n2;
    }

    int addExpr(std::shared_ptr<Fields> field) {
        int n1 = 0;
        string t1 = nextToken();
        if (t1 == "(") {
            n1 = bracketExpr(field);
        } else {
            n1 = immediateExpr(t1, field);
        }
        int n2 = 0;
        string t2 = nextToken();
        if (t2 == "(") {
            n2 = bracketExpr(field);
        } else {
            n2 = immediateExpr(t2, field);
        }
        nextToken();
        return n1 + n2;
    }

    int letExpr(std::shared_ptr<Fields> field) {
        std::shared_ptr<Fields> nextField = std::make_shared<Fields>();
        nextField->parent = field;
        int res = 0;
        while (true) {
            string t1 = nextToken();
            if (t1 == "(") {
                res = bracketExpr(nextField);
                nextToken();
                break;
            }
            string t2 = nextToken();
            if (t2 == ")") {
                res = immediateExpr(t1, nextField);
                break;  
            } else if (t2 == "(") {
                nextField->map[t1] = bracketExpr(nextField);
            } else {
                nextField->map[t1] = immediateExpr(t2, nextField);
            }
        }
        return res;
    }

    int immediateExpr(string const &token, std::shared_ptr<Fields> field) {
        if (token[0] == '-' || (token[0] >= '0' && token[0] <= '9')) {
            return std::stoi(token);
        }
        while (field != nullptr) {
            if (field->map.find(token) != field->map.end()) {
                return field->map[token];
            } else {
                field = field->parent;
            }
        }
        return 0;
    }

public:
    int evaluate(string expression) {
        expr = expression;
        ez = expression.size();
        std::shared_ptr<Fields> field = std::make_shared<Fields>();
        return calcExpr(field);
    }
};