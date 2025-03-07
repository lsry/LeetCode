#include <set>
#include <string>
#include <unordered_map>
#include <utility>
using std::string;
#include <vector>
using std::vector;


class FoodRatings {
    std::unordered_map<string, std::pair<int, string>> foodMap;
    std::unordered_map<string, std::set<std::pair<int, string>>> cusisineMap;
    int N;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        N = foods.size();
        for (int i{0};i < N;++i) {
           foodMap.emplace(foods[i], std::pair<int, string>(ratings[i], cuisines[i]));
           cusisineMap[cuisines[i]].insert(std::pair<int, string>(N - ratings[i], foods[i]));
        }
    }
    
    void changeRating(string food, int newRating) {
        auto &[rate, cuisine] = foodMap[food];
        auto &cuisineSet = cusisineMap[cuisine];
        cuisineSet.erase(std::pair<int, string>(N - rate, food));
        cuisineSet.insert(std::pair<int, string>(N - newRating, food));
        rate = newRating;
    }
    
    string highestRated(string cuisine) {
        return cusisineMap[cuisine].begin()->second;
    }
};

int main() {
    vector<string> foods{"emgqdbo","jmvfxjohq","qnvseohnoe","yhptazyko","ocqmvmwjq"};
    vector<string> cuisines{"snaxol","snaxol","snaxol","fajbervsj","fajbervsj"};
    vector<int> rates{2,6,18,6,5};
    FoodRatings fr(foods, cuisines, rates);
    fr.changeRating("qnvseohnoe",11);
    fr.changeRating("emgqdbo",3);
    fr.changeRating("jmvfxjohq",9);
    fr.changeRating("emgqdbo",14);
    fr.highestRated("snaxol");
}