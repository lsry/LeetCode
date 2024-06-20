#include <cctype>
#include <iomanip>
#include <ios>
#include <sstream>
#include <string>
using std::string;

class Solution {
    long long int checkPrice(string const &sentence, int id, int &nid) {
        int N = sentence.size();
        if ((id - 2 >= 0 && sentence[id - 2] != ' ') || id == N || !std::isdigit(sentence[id])) {
            return -1;
        }
        long long int price = 0;
        for (;id < N && std::isdigit(sentence[id]);++id) {
            price = price * 10 + (sentence[id] - '0');
        }
        if (id == N || sentence[id] == ' ') {
            nid = id;
            return price;
        }
        return -1;
    }
public:
    string discountPrices(string sentence, int discount) {
        std::stringstream ss;
        int N = sentence.size();
        for (int i = 0;i < N;++i) {
            if (sentence[i] != '$') {
                ss << sentence[i];
                continue;
            }
            int n = 0;
            long long int p = checkPrice(sentence, i + 1, n);
            if (p >= 0) {
                double p1 = 1.0 * p * (100 - discount) / 100.0;
                ss << sentence[i] << std::setiosflags(std::ios::fixed) << std::setprecision(2) << p1;
                i = n - 1;
            } else {
                ss << sentence[i];
            }
        }
        return ss.str();
    }
};