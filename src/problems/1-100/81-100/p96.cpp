#include "problems/problem_registry.hpp"

#include <vector>
#include <fstream>
#include <string>

struct Sudoku
{
    int digit[9][9];
    bool fixed[9][9];
};

std::vector<Sudoku> readSudokus(const std::string &filename)
{
    // Open file
    std::ifstream ifs(filename);
    if(!ifs.is_open()) {
        throw std::runtime_error("[P 96] Cannot read file: " + filename);
    }

    // Read file
    const size_t TotalSudokus = 50;
    std::vector<Sudoku> sudokus;
    sudokus.resize(TotalSudokus);
    for(size_t n = 0; n < sudokus.size(); ++n) {
        std::string line;
        std::getline(ifs, line); // First line is garbage
        for(size_t row = 0; row < 9; ++row) {
            std::getline(ifs, line);
            for(size_t col = 0; col < 9; ++col) {
                sudokus[n].digit[row][col] = static_cast<int>(line[col] - '0');
                sudokus[n].fixed[row][col] = (sudokus[n].digit[row][col] == 0 ? false : true);
            }
        }
    }

    // Close file
    ifs.close();

    return sudokus;
}

bool checkRow(size_t row, const Sudoku &sudoku)
{
    bool check[9] = {false};
    for(size_t col = 0; col < 9; ++col) {
        if(sudoku.digit[row][col] != 0) {
            if(!check[sudoku.digit[row][col] - 1]) {
                check[sudoku.digit[row][col] - 1] = true;
            } else {
                return false;
            }
        }
    }
    return true;
}

bool checkColumn(size_t col, const Sudoku &sudoku)
{
    bool check[9] = {false};
    for(size_t row = 0; row < 9; ++row) {
        if(sudoku.digit[row][col] != 0) {
            if(!check[sudoku.digit[row][col] - 1]) {
                check[sudoku.digit[row][col] - 1] = true;
            } else {
                return false;
            }
        }
    }
    return true;
}

bool checkBox(size_t row, size_t col, const Sudoku &sudoku)
{
    bool check[9] = {false};
    size_t boxRow = row / 3;
    size_t boxCol = col / 3;
    for(size_t i = 0; i < 3; ++i) {
        for(size_t j = 0; j < 3; ++j) {
            if(sudoku.digit[3* boxRow + i][3 * boxCol + j] != 0) {
                if(!check[sudoku.digit[3* boxRow + i][3* boxCol + j] - 1]) {
                    check[sudoku.digit[3* boxRow + i][3* boxCol + j] - 1] = true;
                } else {
                    return false;
                }
            }
        }
    }
    return true;
}

int solveByBacktracking(Sudoku &sudoku, size_t row, size_t col)
{
    if(row > 8) {
        throw std::exception("Solution found");
    }
    while(sudoku.fixed[row][col]) {
        col += 1;
        if(col > 8) {
            col = 0;
            row += 1;
        }
        if(row > 8) {
            throw std::exception("Solution found");
        }
    }
    for(int i = 1; i <= 9; ++i) {
        sudoku.digit[row][col] = i;
        if(checkRow(row, sudoku)
           && checkColumn(col, sudoku)
           && checkBox(row, col, sudoku)) {
            if(col + 1 > 8) {
                solveByBacktracking(sudoku, row + 1, 0);
            } else {
                solveByBacktracking(sudoku, row, col + 1);
            }
        } else {
            sudoku.digit[row][col] = 0;
        }
    }
    sudoku.digit[row][col] = 0;
}

int64_t count(const std::vector<Sudoku> &sudokus)
{
    int64_t sum = 0;
    for(const Sudoku &s: sudokus) {
        sum += s.digit[0][0] * 100;
        sum += s.digit[0][1] * 10;
        sum += s.digit[0][2];
    }

    return sum;
}

int64_t problem_96()
{
    int topLeftSum = 0;
    std::vector<Sudoku> sudokus = readSudokus("data/p96_sudoku.txt");
    for(int i = 0; i < sudokus.size(); ++i) {
        try {
            solveByBacktracking(sudokus[i], 0, 0);
        } catch(...)
        {

        }
    }

    return count(sudokus);
}

REGISTER_FUNCTION(96, problem_96);
