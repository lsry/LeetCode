#include <array>
#include <string>
#include <utility>
#include <vector>
using std::string;

class Spreadsheet {
    std::vector<std::array<int, 26>> spread;

    std::pair<int, int> getRC(string const &cell) {
        int C = cell[0] - 'A';
        int R = 0;
        for (int i = 1;i < cell.size();++i) {
            R = R * 10 + (cell[i] - '0');
        }
        return {R, C};
    }

    int getFomulaCellValue(string const &formula) {
        if (formula.empty()) {
            return 0;
        }
        if (formula[0] >= 'A' && formula[0] <= 'Z') {
            return getCellValue(formula);
        }
        int r{0};
        for (char c : formula) {
            r = r * 10 + (c - '0');
        }
        return r;
    }

    int getCellValue(string const &cell) {
        auto [R, C] = getRC(cell);
        if (R > spread.size()) {
            return 0;
        }
        return spread[R - 1][C];
    }
public:
    Spreadsheet(int rows): spread(rows, std::array<int, 26>{0}) {}
    
    void setCell(string cell, int value) {
        auto [R, C] = getRC(cell);
        while (spread.size() < R) {
            spread.emplace_back(std::array<int, 26>{0});
        }
        spread[R - 1][C] = value;
    }
    
    void resetCell(string cell) {
        auto [R, C] = getRC(cell);
        if (R <= spread.size()) {
            spread[R - 1][C] = 0;
        }
    }
    
    int getValue(string formula) {
        int i = 1;
        string f1, f2;
        for (;i < formula.size() && formula[i] != '+';++i) {
            f1.push_back(formula[i]);
        }
        for (i = i + 1;i < formula.size();++i) {
            f2.push_back(formula[i]);
        }
        return getFomulaCellValue(f1) + getFomulaCellValue(f2);
    }
};