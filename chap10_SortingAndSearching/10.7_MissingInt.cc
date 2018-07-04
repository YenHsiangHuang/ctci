// LC #41
// Your algorithm should run in O(n) time and uses constant extra space.
// Similar: LC #268
#include <iostream>
#include <vector>
#include <climits>
#include <bitset>

int firstMissingPositive(std::vector<int>& nums) {
    std::bitset<32767> bit;
    for (auto& n : nums) {
        if (n > 0) bit[n-1] = 1;
    }

    int res = 0;
    while (bit.test(res)) ++res;
    return res + 1;
}


int main(int argc, const char *argv[])
{
    std::vector<int> test1 = {1,2,0};
    std::vector<int> test2 = {3,4,-1,1};
    std::vector<int> test3 = {7,8,9,11,12};

    std::cout << firstMissingPositive(test1) << std::endl;
    std::cout << firstMissingPositive(test2) << std::endl;
    std::cout << firstMissingPositive(test3) << std::endl;
    return 0;
}
