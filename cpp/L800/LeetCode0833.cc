#include <string>
using std::string;

#include <vector>
using std::vector;

#include <queue>

class Solution {
    bool checkEqual(string const &s, int start, string const &target) {
        if (start + target.size() > s.size()) {
            return false;
        }
        for (int i{0};start + i < s.size() && i < target.size();++i) {
            if (s[start + i] != target[i]) {
                return false;
            }
        }
        return true;
    }
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int K = indices.size();
        int N = s.size();
        auto f {[](std::tuple<int, string, string> const &t1, std::tuple<int, string, string> const &t2) {
            return std::get<0>(t1) > std::get<0>(t2);
        }};
        std::priority_queue<std::tuple<int, string, string>, std::vector<std::tuple<int, string, string>>, decltype(f)> pq(f);
        for (int i = 0;i < K;++i) {
            pq.emplace(std::make_tuple(indices[i], sources[i], targets[i]));
        }
        string r;
        for (int i{0};i < N;++i) {
            while (!pq.empty() && std::get<0>(pq.top()) < i) {
                pq.pop();
            }
            bool flag{false};
            while (!pq.empty() && std::get<0>(pq.top()) == i) {
                if (checkEqual(s, i, std::get<1>(pq.top()))) {
                    r.append(std::get<2>(pq.top()));
                    i += std::get<1>(pq.top()).size() - 1;
                    flag = true;
                    break;
                } else {
                    pq.pop();
                }
            }
            if (!flag) {
                r.push_back(s[i]);
            }
        }
        return r;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> ids{46,29,2,44,31,26,42,9,38,23,36,12,16,7,33,18};
    vector<string> sou{"rym","kv","nbzxu","vx","js","tp","tc","jta","zqm","ya","uz","avm","tz","wn","yv","ird"}, tars{"gfhc","uq","dntkw","wql","s","dmp","jqi","fp","hs","aqz","ix","jag","n","l","y","zww"};
    s.findReplaceString("mhnbzxkwzxtaanmhtoirxheyanoplbvjrovzudznmetkkxrdmr", ids, sou, tars);
    return 0;
}
