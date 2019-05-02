// LC #46
#include <string>
#include <vector>
#include "printer.hpp"

//#define RUN_CTCI
#define RUN_LC

#ifdef RUN_CTCI
// CtCI: permutations of a string without dup
void permute(std::string& strs, int begin, std::vector<std::string>& res) {
    if (begin >= strs.length()) {
        res.push_back(strs);
        return;
    }
    for (int i = begin; i < strs.length(); ++i) {
        std::swap(strs[begin], strs[i]);
        permute(strs, begin + 1, res);
        std::swap(strs[begin], strs[i]);
    }
}

std::vector<std::string> permute(std::string& strs) {
    std::vector<std::string> res;
    permute(strs, 0, res);
    return res;
}
#endif  // RUN_CTCI

#ifdef RUN_LC
// LC #46: permutations of distinct integers
void permute(std::vector<int>& nums, int begin,
             std::vector<std::vector<int>>& res) {
    if (begin >= nums.size()) {
        res.push_back(nums);
        return;
    }
    for (int i = begin; i < nums.size(); ++i) {
        std::swap(nums[begin], nums[i]);
        permute(nums, begin + 1, res);
        std::swap(nums[begin], nums[i]);
    }
}

std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    std::vector<std::vector<int>> res;
    permute(nums, 0, res);
    return res;
}
#endif  // RUN_LC

int main(int argc, const char* argv[]) {
#ifdef RUN_CTCI
    std::string testStr("abcd");
    std::cout << "[" << testStr << "]" << std::endl;
    printVec(permute(testStr));
#endif  // RUN_CTCI

#ifdef RUN_LC
    std::vector<int> test = {1, 2, 3};
    printVec(test);
    printVec2(permute(test));
#endif  // RUN_LC
    return 0;
}
