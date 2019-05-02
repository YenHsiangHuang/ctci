// LC #41
// Your algorithm should run in O(n) time and uses constant extra space.
// Similar: LC #268
#include <bitset>
#include <climits>
#include <iostream>
#include <vector>
#include "printer.hpp"

int firstMissingPositive(std::vector<int>& nums) {
    printVec(nums);
    int i = 0;
    int n = nums.size();

    while (i < n) {
        if (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
            std::swap(nums[i], nums[nums[i] - 1]);
            printVec(nums);
        } else {
            ++i;
        }
    }

    for (i = 0; i < n; ++i)
        if (nums[i] != i + 1) return i + 1;

    return n + 1;
}

int main(int argc, const char* argv[]) {
    std::vector<int> test1 = {1, 2, 0};
    std::vector<int> test2 = {3, 4, -1, 1};
    std::vector<int> test3 = {7, 8, 9, 11, 12};

    std::cout << firstMissingPositive(test1) << std::endl;
    std::cout << firstMissingPositive(test2) << std::endl;
    std::cout << firstMissingPositive(test3) << std::endl;
    return 0;
}
