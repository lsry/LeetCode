#include <unordered_map>
#include <vector>
using std::vector;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
    int getImportance(int id, std::unordered_map<int, int> const &mp, vector<Employee*> const &employees) {
        auto it = mp.find(id);
        if (it == mp.end()) {
            return 0;
        }
        Employee *cur = employees[it->second];
        int importance = cur->importance;
        for (int nextId : cur->subordinates) {
            importance += getImportance(nextId, mp, employees);
        }
        return importance;
    }
public:
    int getImportance(vector<Employee*> employees, int id) {
        std::unordered_map<int, int> emplyeeMap;
        for (int i = 0;i < employees.size();++i) {
            emplyeeMap[employees[i]->id] = i;
        }
        return getImportance(id, emplyeeMap, employees);
    }
};