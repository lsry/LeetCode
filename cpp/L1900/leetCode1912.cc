#include <functional>
#include <queue>
#include <set>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>
using std::vector;

class MovieRentingSystem {
    std::unordered_map<int, std::unordered_map<int, int>> shopMoviePrice;
    std::unordered_map<int, std::set<std::pair<int, int>>> unrentMap;
    std::priority_queue<std::tuple<int, int, int>, vector<std::tuple<int, int, int>>, std::greater<std::tuple<int, int, int>>> rentQueue;
    std::set<std::tuple<int, int, int>> rentFlag;
    std::set<std::tuple<int, int, int>> undeleted; // 防止因爲先借出再歸還然後再借出導致重複添加問題
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (vector<int> const &entry : entries) {
            shopMoviePrice[entry[0]][entry[1]] = entry[2];
            unrentMap[entry[1]].insert(std::pair<int, int>(entry[2], entry[0]));
        }
    }
    
    vector<int> search(int movie) {
        std::set<std::pair<int, int>> &st{unrentMap[movie]};
        vector<int> r;
        int i = 0;
        auto it{st.begin()};
        for (;i < 5 && it != st.end();++i, ++it) {
            r.push_back(it->second);
        }
        return r;
    }
    
    void rent(int shop, int movie) {
        int price = shopMoviePrice[shop][movie];
        unrentMap[movie].erase(std::pair<int, int>(price, shop));
        std::tuple<int, int, int> t{std::tuple<int, int, int>(price, shop, movie)};
        if (!undeleted.contains(t)) {
            rentQueue.push(t);
        }
        rentFlag.insert(t);
    }
    
    void drop(int shop, int movie) {
        int price = shopMoviePrice[shop][movie];
        std::tuple<int, int, int> t{std::tuple<int, int, int>(price, shop, movie)};
        rentFlag.erase(t);
        undeleted.insert(t);
        unrentMap[movie].insert(std::pair<int, int>(price, shop));
    }
    
    vector<vector<int>> report() {
        vector<std::tuple<int, int, int>> rented;
        for (int i = 0;i < 5 && !rentQueue.empty();) {
            std::tuple<int, int, int> t{rentQueue.top()};
            rentQueue.pop();
            if (rentFlag.contains(t)) {
                rented.emplace_back(t);
                ++i;
            } else {
                undeleted.erase(t);
            }
        }
        vector<vector<int>> r;
        for (std::tuple<int, int, int> t : rented) {
            r.emplace_back(vector<int>{std::get<1>(t), std::get<2>(t)});
            rentQueue.push(t);
        }
        return r;
    }
};