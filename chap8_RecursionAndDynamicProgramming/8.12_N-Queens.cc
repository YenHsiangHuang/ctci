// LC #51
#include <iostream>
#include <string>
#include <vector>

void printBoard(std::vector<std::vector<std::string>>& board, int n) {
    for (auto& b : board) {
        for (auto& line : b) std::cout << line << std::endl;
        std::cout << std::endl;
    }
}
void printBoard(std::vector<std::vector<std::string>>&& board, int n) {
    printBoard(board, n);
}

bool isValid(std::vector<int>& pos, int row, int col) {
    for (int i = 0; i < row; ++i) {  // Check previous queens
        // same column OR on diagonal
        if (pos[i] == col || (std::abs(i - row) == std::abs(pos[i] - col)))
            return false;
    }
    return true;
}

void solveNQueens(int& n, std::vector<std::vector<std::string>>& res, int row,
                  std::vector<int>& pos, std::vector<std::string>& board) {
    if (row == n) {
        res.push_back(board);
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (!isValid(pos, row, col)) continue;
        pos[row] = col;  // Record position of new queen
        board[row][col] = 'Q';
        solveNQueens(n, res, row + 1, pos, board);
        board[row][col] = '.';
    }
}

std::vector<std::vector<std::string>> solveNQueens(int n) {
    std::vector<std::vector<std::string>> res;
    std::vector<std::string> board(n, std::string(n, '.'));
    std::vector<int> pos(n);
    solveNQueens(n, res, 0, pos, board);
    return res;
}

int main(int argc, const char* argv[]) {
    int s = 4;
    printBoard(solveNQueens(s), s);
    return 0;
}
