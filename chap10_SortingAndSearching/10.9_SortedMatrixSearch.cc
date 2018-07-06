// LC #74
// LC #240
#include <algorithm>
#include <iostream>
#include <vector>

// LC #74
// Matrix is sorted in strictly ascending order
// Idea: Treat them as a single sorted array
bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    // O(log(m * n))
    if (matrix.empty() || matrix[0].empty()) return false;

    int m = matrix.size(), n = matrix[0].size();
    int lb = 0, ub = m * n - 1;

    int row;
    while (lb != ub) {
        int guess = (lb + ub - 1) >> 1;
        row = guess / n;
        if (matrix[row][guess - row * n] < target)
            lb = guess + 1;
        else
            ub = guess;
    }

    row = ub / n;
    return matrix[row][ub - row * n] == target;

#if 0
    // O(m), m is number of row
    if (matrix.empty() || matrix[0].empty()) return false;

    // Locate row
    int r = 0, n = matrix[0].size();
    while (r < matrix.size() && target > matrix[r][n - 1]) ++r;
    if (r == matrix.size()) return false;

    // Locate column using binary search
    return binary_search(matrix[r].begin(), matrix[r].end(), target);
#endif
}

bool searchMatrix(std::vector<std::vector<int>>&& matrix, int target) {
    return searchMatrix(matrix, target);
}

// LC #240
// Matrix is sorted in ascending order
// Idea: the upper right most element is special: larger than elements on its
// left and smaller than elements below
bool searchMatrixII(std::vector<std::vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;

    int m = matrix.size(), n = matrix[0].size();
    int row = 0, col = n - 1;  // Start with upper right corner

    while (row < m && col >= 0) {
        if (matrix[row][col] == target) return true;
        if (matrix[row][col] > target)  // Go left
            --col;
        else                            // Go down
            ++row;
    }
    return false;

#if 0
    if (matrix.empty() || matrix[0].empty()) return false;

    int n = matrix[0].size();
    for (int r = 0; r < matrix.size(); ++r) {
        if (matrix[r][0] > target || matrix[r][n - 1] < target) continue;
        if (binary_search(matrix[r].begin(), matrix[r].end(), target)) return true;
    }

    return false;
#endif
}

bool searchMatrixII(std::vector<std::vector<int>>&& matrix, int target) {
    return searchMatrixII(matrix, target);
}

int main(int argc, const char* argv[]) {
    std::vector<std::vector<int>> matrix = {{ 1,  3,  5,  7},
                                            {10, 11, 16, 20},
                                            {23, 30, 34, 50}};
    std::cout << searchMatrix(matrix, 3) << std::endl;   // 1
    std::cout << searchMatrix(matrix, 13) << std::endl;  // 0
    std::cout << searchMatrix(std::vector<std::vector<int>>{{}}, 1)
              << std::endl;  // 0
    std::cout << searchMatrix(std::vector<std::vector<int>>{{}, {}}, 1)
              << std::endl;  // 0
    std::cout << searchMatrix(std::vector<std::vector<int>>{{1}}, 1)
              << std::endl;  // 1
    std::cout << searchMatrix(std::vector<std::vector<int>>{{1, 3}}, 3)
              << std::endl;  // 1

    std::cout << std::endl;

    std::vector<std::vector<int>> matrixII = {{ 1,  4,  7, 11, 15},
                                              { 2,  5,  8, 12, 19},
                                              { 3,  6,  9, 16, 22},
                                              {10, 13, 14, 17, 24},
                                              {18, 21, 23, 26, 30}};
    std::cout << searchMatrixII(matrixII, 5) << std::endl;   // 1
    std::cout << searchMatrixII(matrixII, 20) << std::endl;  // 0
    std::cout << searchMatrixII(std::vector<std::vector<int>>{{}}, 1)
              << std::endl;  // 0
    std::cout << searchMatrixII(std::vector<std::vector<int>>{{}, {}}, 1)
              << std::endl;  // 0
    std::cout << searchMatrixII(std::vector<std::vector<int>>{{1}}, 1)
              << std::endl;  // 1

    return 0;
}
