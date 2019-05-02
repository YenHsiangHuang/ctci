// LC #78 and #90
#include <cmath>
#include <vector>
#include "printer.hpp"

// LC #78 values are distinct
std::vector<std::vector<int>> subsets(std::vector<int>& sets) {
    std::vector<std::vector<int>> res(1);
    res.reserve(std::pow(2, sets.size()));

    for (int i = 0; i < sets.size(); i++) {
        int oriSize = res.size();
        for (int j = 0; j < oriSize; j++) {
            res.push_back(res[j]);
            res[j + oriSize].push_back(sets[i]);
        }
    }
    return res;
}
/**
   Another solution for #78
   For each subset, we have two choices for each element, "Yes(appear)" or
   "No(not appear)". So this becomes simple.

   Example:
     1   2   3
    -----------
     0   0   0    Thus, for integer k, it appears 2^k times with interval 2^k
     1   0   0
     0   1   0
     1   1   0
     0   0   1
     1   0   1
     0   1   1
     1   1   1
 */

// LC #90 might have duplicates
//std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& sets) {}

int main(int argc, const char* argv[]) {
    std::vector<int> testCase = {1, 2, 3};
    printVec(testCase);
    auto toPrint = subsets(testCase);
    printVec2(toPrint);

    //std::vector<int> dupTestCase = {1, 2, 2};
    //print2DVec(subsetsWithDup(dupTestCase));

    return 0;
}
