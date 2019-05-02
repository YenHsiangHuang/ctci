// LC #280 Wiggled Sort (Locked) & #324 Wiggled Sort II
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <vector>
#include "printer.hpp"

enum Mode { One, Two, Three };

/**
   Wiggle Sort, O(nlogn) time
   Sort the array first and then do pairwise swap, starting from the third
   element.
 */
void wiggleSortNlogN(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    for (int i = 2; i < nums.size(); i += 2) std::swap(nums[i - 1], nums[i]);
}

/**
   Wiggle Sort, O(n) time
   Go through each element and make sure it's valid.
 */
void wiggleSortN(std::vector<int>& nums) {
    for (int i = 1; i < nums.size(); ++i) {
        if ( (i & 1) && nums[i] >= nums[i - 1]) continue;
        if (!(i & 1) && nums[i] <= nums[i - 1]) continue;
        std::swap(nums[i], nums[i - 1]);
    }
}

// Modified from LC #75 Sort Color
void sortColors(std::vector<int>& nums) {
    int n = nums.size();
    int lb = 0, ub = n - 1;
    int i = lb, mid = nums[n / 2];

#define A(i) nums[(1 + 2 * (i)) % (n | 1)]  // Index mapping

    while (i <= ub) {
        if (A(i) > mid) {
            std::swap(A(lb++), A(i++));
        } else if (A(i) < mid) {
            std::swap(A(ub--), A(i));
        } else {
            ++i;
        }
    }
}

/**
   Wiggle Sort II, O(n) time
   First find out the nth largest element and put it at nth position using
   std::nth_element. Second apply color sorting with index mapping.

   Index mapping:
   The index 0 1 2 3 4 5 will be mapped to 1 3 5 0 2 4 by index mapping. Color
   sort meant to put same elements together. But in here we want to put all
   elements larger than a specific value in odd index, and the others in even
   index. So we apply index mapping and do color sort to mapped array.
 */
void wiggleSortII(std::vector<int>& nums) {
    std::nth_element(nums.begin(), nums.begin() + (nums.size() / 2),
                     nums.end());
    sortColors(nums);
}

// Generate random test case with length n
std::vector<int> genTest(int n) {
    std::vector<int> test(n);
    for (int i = 0; i < n; ++i) test[i] = rand() % 10;
    return test;
}

void runTest(int n, Mode mode) {
    std::vector<int> nums;
    nums = genTest(n);
    printVec(nums);
    switch (mode) {
        case One:
            wiggleSortN(nums);
            break;
        case Two:
            wiggleSortNlogN(nums);
            break;
        case Three:
            wiggleSortII(nums);
            break;
    }
    std::cout << "    ";
    printVec(nums);
}

int main(int argc, const char* argv[]) {
    srand(time(nullptr));

    runTest(6, Three);
    runTest(7, Three);
    runTest(8, Three);

    return 0;
}
