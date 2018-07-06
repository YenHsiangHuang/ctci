// LC #280 Wiggled Sort (Locked)
// LC #324 Wiggled Sort II
#include <algorithm>
#include <vector>
#include "printer.h"

void wiggleSort(std::vector<int>& nums) {
    // O(NlogN)
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i += 2) {
        std::swap(nums[i], nums[i + 1]);
    }
}

void wiggleSortII(std::vector<int>& nums) {
}

int main(int argc, const char *argv[])
{
    std::vector<int> test1 = {1, 5, 1, 1, 6, 4};
    std::vector<int> test2 = {1, 3, 2, 2, 3, 1};
    std::vector<int> nums;

    nums = test1;
    wiggleSort(nums);
    printVec(nums);

    nums = test2;
    wiggleSort(nums);
    printVec(nums);

    return 0;
}
