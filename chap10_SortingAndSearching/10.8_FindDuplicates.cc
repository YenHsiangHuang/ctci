// The Find Duplicates problem in CtCI is different from LC. I decided to deal
// with the one in LC instead of CtCI for now.

// 1. You must not modify the array (assume the array is read only).
// 2. You must use only constant, O(1) extra space.
// 3. Your runtime complexity should be less than O(n^2).
// 4. There is only one duplicate number in the array, but it could be repeated
// more than once.
#include <iostream>
#include <vector>

// Same idea as in Missing Integer
int findDuplicate(std::vector<int>& nums) {
    int i = 0, n = nums.size();
    while (i < n) {
        if (i != nums[i] - 1) {
            if (nums[i] != nums[nums[i] - 1])
                std::swap(nums[i], nums[nums[i] - 1]);
            else
                return nums[i];
        } else {
            ++i;
        }
    }
    return -1;
}

int findDuplicate(std::vector<int>&& nums) { return findDuplicate(nums); }

int main(int argc, const char* argv[]) {
    std::cout << findDuplicate(std::vector<int>{1, 3, 4, 2, 2}) << std::endl;
    std::cout << findDuplicate(std::vector<int>{3, 1, 3, 4, 2}) << std::endl;
    return 0;
}
