// LC #46
#include <string>
#include <vector>
#include "mathematical.h"
#include "printer.h"

// CtCI: permutations of a string without dup
std::vector<std::string> permute(std::string& strs) {
    std::vector<std::string> res(3, "abc");
    return res;
}

// LC #46: permutations of distinct integers
/*
std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    if (nums.empty()) return std::vector<std::vector<int>>();

    std::vector<std::vector<int>> res(1, std::vector<int>(1, nums.front()));
    auto facSeries = factorialSeries(nums.size());

    res.reserve(facSeries.back());

    // For every new elem
    for (int i = 1; i < nums.size(); ++i) {
        // For each vector in res
        unsigned nVec = res.size();
        unsigned vecIdx = facSeries[i];
        size_t insertEnd = res[0].size();
        for (int j = 0; j < nVec; ++j) {
            // For each position in a vector
            for (unsigned insertPos = 0; insertPos < insertEnd; ++insertPos) {
                res.push_back(res[j]);
                res[vecIdx].insert(res[vecIdx].begin()+insertPos, nums[i]);
                ++vecIdx;
            }
            res[j].push_back(nums[i]);
        }
    }

    return res;
}
*/

void permute(std::vector<int>& nums, int begin, std::vector<std::vector<int>>& res) {
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

int main(int argc, const char* argv[]) {
    std::vector<int> test = {1,2,3,4};
    printVec(test);
    printVec2(permute(test));

    //std::string testStr("abc");
    //printVec(permute(testStr));
    return 0;
}
