// LC #63
#include <iostream>
#include <vector>

// time: O(row*column), space: O(column)
int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
    if (obstacleGrid.empty()) return 0;

    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    std::vector<int> numPath(n);

    int j;
    for (int i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (obstacleGrid[i][j])
                numPath[j] = 0;
            else {
                if (j == 0)
                    numPath[j] = (i == 0 || numPath[j] == 1) ? 1 : 0;
                else
                    numPath[j] += numPath[j - 1];
            }
        }
    }

    return numPath[j - 1];
}

int main(int argc, const char* argv[]) {
    int m = 8, n = 5;
    std::vector<std::vector<int>> obstacleGrid(m, std::vector<int>(n));
    obstacleGrid[2][3] = 1;
    obstacleGrid[5][1] = 1;
    obstacleGrid[1][1] = 1;

    std::cout << uniquePathsWithObstacles(obstacleGrid) << std::endl;

    std::cin.get();
}
