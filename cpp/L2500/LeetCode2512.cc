#include <queue>
#include <unordered_set>
#include <vector>
using std::vector;
#include <string>
using std::string;

class Solution {
    int getStudentGrade(std::unordered_set<std::string> const &positives, std::unordered_set<std::string> const &negatives, string const &report) {
        int grade{0};
        std::size_t rz{report.size()};
        for (std::size_t i{0};i < rz;++i) {
            if (report[i] == ' ') {
                continue;
            }
            std::size_t j{i};
            while (j < rz && report[j] != ' ') {
                ++j;
            }
            string word{report.substr(i, j -  i)};
            if (positives.find(word) != positives.end()) {
                grade += 3;
            } else if (negatives.find(word) != negatives.end()) {
                grade -= 1;
            }
            i = j;
        }
        return grade;
    }
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        if (k <= 0) {
            return {};
        }
        std::unordered_set<std::string> positives, negatives;
        for (string const &ps : positive_feedback) {
            positives.emplace(ps);
        }
        for (string const &ps : negative_feedback) {
            negatives.emplace(ps);
        }
        auto f{[](std::pair<int, int> const &p1, std::pair<int, int> const &p2) {
            return p1.first == p2.first ? p1.second < p2.second : p1.first > p2.first;
        }};
        // grade, id
        std::priority_queue<std::pair<int, int>, vector<std::pair<int, int>>, decltype(f)> pq(f);
        for (int i = 0;i < student_id.size();++i) {
            int grade{getStudentGrade(positives, negatives, report[i])};
            if (pq.size() < k) {
                pq.push(std::pair<int, int>(grade, student_id[i]));
            } else if (pq.top().first < grade || (pq.top().first == grade && pq.top().second > student_id[i])) {
                pq.pop();
                pq.push(std::pair<int, int>(grade, student_id[i]));
            }
        }
        vector<int> res(k, 0);
        for (int i = k - 1;i >= 0;--i) {
            res[i] = pq.top().second;
            pq.pop();
        }
        return res;
    }
};