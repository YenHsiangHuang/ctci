// LC #78 and #90
#include <cmath>
#include <vector>

void print2DVec(std::vector<std::vector<int>>& vv) {
    printf("[\n");
    for (auto& v : vv) {
        (v.empty()) ? printf("    [ ") : printf("    [");
        for (auto& elem : v) printf("%d ", elem);
        printf("\b]\n");
    }
    printf("]\n");
}
void print2DVec(std::vector<std::vector<int>>&& vv) { print2DVec(vv); }

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
std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& sets) {}

int main(int argc, const char* argv[]) {
    //std::vector<int> testCase;
    //std::vector<int> testCase = {1};
    std::vector<int> testCase = {1, 2, 3};
    //std::vector<int> testCase = {4, 1, 0};
    //std::vector<int> testCase = {1, 2, 3, 4};
    print2DVec(subsets(testCase));

    std::vector<int> dupTestCase = {1, 2, 2};
    print2DVec(subsetsWithDup(dupTestCase));

    return 0;
}
