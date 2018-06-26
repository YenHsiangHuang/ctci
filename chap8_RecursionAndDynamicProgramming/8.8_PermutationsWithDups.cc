// LC #47
#include <algorithm>
#include <unordered_set>
#include <vector>
#include "printer.h"

#define RUN_CTCI
#define RUN_LC

#ifdef RUN_CTCI
void permuteUnique(std::string& nums, int begin,
                   std::vector<std::string>& res) {
    if (begin >= nums.length()) {
        res.push_back(nums);
        return;
    }
    std::unordered_set<int> used;
    for (int i = begin; i < nums.length(); ++i) {
        if (used.count(nums[i])) continue;
        used.insert(nums[i]);
        std::swap(nums[begin], nums[i]);
        permuteUnique(nums, begin + 1, res);
        std::swap(nums[begin], nums[i]);
    }
}

std::vector<std::string> permuteUnique(std::string& nums) {
    std::vector<std::string> res;
    permuteUnique(nums, 0, res);
    return res;
}
#endif  // RUN_CTCI

// LC #47: permutation of a set of numbers that might contain duplicates.
#ifdef RUN_LC
void permuteUnique(std::vector<int>& nums, int begin,
                   std::vector<std::vector<int>>& res) {
    if (begin >= nums.size()) {
        res.push_back(nums);
        return;
    }
    std::unordered_set<int> used;
    for (int i = begin; i < nums.size(); ++i) {
        if (used.count(nums[i])) continue;
        used.insert(nums[i]);
        std::swap(nums[begin], nums[i]);
        permuteUnique(nums, begin + 1, res);
        std::swap(nums[begin], nums[i]);
    }
}

std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
    std::vector<std::vector<int>> res;
    permuteUnique(nums, 0, res);
    return res;
}
#endif  // RUN_LC

int main(int argc, const char* argv[]) {
#ifdef RUN_LC
    // std::vector<int> test = {1, 1, 1};
    // std::vector<int> test = {1, 1, 2};
    // std::vector<int> test = {1, 2, 2};
    std::vector<int> test = {1, 2, 3};
    // std::vector<int> test = {1, 1, 2, 2};
    printVec(test);
    printVec2(permuteUnique(test));
#endif  // RUN_LC
#ifdef RUN_CTCI
    //std::string testS = "aab";
    //std::string testS = "abb";
    //std::string testS = "aaa";
    std::string testS = "aabb";
    //std::string testS = "abc";
    std::cout << testS << std::endl;
    printVec(permuteUnique(testS));

#endif  // RUN_CTCI
    return 0;
}
