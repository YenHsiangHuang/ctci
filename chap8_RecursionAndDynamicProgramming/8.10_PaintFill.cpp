// LC #733
#include <vector>
#include "printer.hpp"

// Typical DFS
void floodFill(std::vector<std::vector<int>>& image, int sr, int sc,
               int& newColor, int& oldColor, size_t& wid, size_t& hei) {
    if (sr >= hei || sr < 0 || sc >= wid || sc < 0 || image[sr][sc] != oldColor)
        return;

    image[sr][sc] = newColor;
    floodFill(image, sr + 1, sc, newColor, oldColor, wid, hei);
    floodFill(image, sr - 1, sc, newColor, oldColor, wid, hei);
    floodFill(image, sr, sc + 1, newColor, oldColor, wid, hei);
    floodFill(image, sr, sc - 1, newColor, oldColor, wid, hei);
}

std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image,
                                        int sr, int sc, int newColor) {
    if (newColor == image[sr][sc]) return image;

    std::vector<std::vector<int>> res = image;
    size_t wid = image[0].size(), hei = image.size();
    floodFill(res, sr, sc, newColor, image[sr][sc], wid, hei);
    return res;
}

int main(int argc, const char* argv[]) {
    std::vector<std::vector<int>> image;
    image.push_back(std::vector<int>{0, 1, 1});
    image.push_back(std::vector<int>{0, 1, 1});
    printVec2(image);
    printVec2(floodFill(image, 1, 1, 1));

    return 0;
}
