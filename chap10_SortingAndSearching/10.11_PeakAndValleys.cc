// LC #280 Wiggled Sort (Locked)
// LC #324 Wiggled Sort II
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include "printer.h"

void wiggleSortN(std::vector<int>& nums) {
    // O(N)
    for (int i = 1; i < nums.size(); ++i) {
        if ( (i & 1) && nums[i] >= nums[i - 1]) continue;
        if (!(i & 1) && nums[i] <= nums[i - 1]) continue;
        std::swap(nums[i], nums[i - 1]);
    }
}

// valley - peak - valley - peak ...
void wiggleSortNlogN(std::vector<int>& nums) {
    // O(NlogN)
    std::sort(nums.begin(), nums.end());
    for (int i = 2; i < nums.size(); i += 2) std::swap(nums[i - 1], nums[i]);
}

void wiggleSortII(std::vector<int>& nums) {
    // Background: findKthLargestNumber (nth_element in c++), sort color
}

std::vector<int> genTest(int n) {
    std::vector<int> test(n);
    for (int i = 0; i < n; ++i) test[i] = rand()%10;
    return test;
}

int main(int argc, const char *argv[])
{
    srand(time(nullptr));
    std::vector<int> test1 = {1, 5, 1, 1, 6, 4};
    std::vector<int> test2 = {1, 3, 2, 2, 3, 1};
    std::vector<int> nums;

    nums = genTest(6);
    printVec(nums);
    wiggleSortII(nums);
    std::cout << "    ";
    printVec(nums);

    nums = genTest(7);
    printVec(nums);
    wiggleSortII(nums);
    std::cout << "    ";
    printVec(nums);

    nums = genTest(8);
    printVec(nums);
    wiggleSortII(nums);
    std::cout << "    ";
    printVec(nums);

    return 0;
}
