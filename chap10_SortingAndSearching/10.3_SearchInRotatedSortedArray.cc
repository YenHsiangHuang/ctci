// LC #33
#include <iostream>
#include <vector>

int search(std::vector<int>& nums, int target) {
    if (nums.empty()) return -1;
    int head = 0, tail = nums.size() - 1;
    if (nums[tail] == target) return tail;
    int guess = (head + tail) / 2, lastGuess;

    lastGuess = tail;
    while (std::abs(lastGuess - guess) > 0) {
        if (nums[guess] == target) return guess;
        if (nums[guess] > nums[head]) {  // On the left side
            if (nums[guess] > target && target >= nums[head]) {
                tail = guess;
            } else {
                head = guess;
            }
        } else {  // On the right side
            if (nums[guess] < target && target <= nums[tail]) {
                head = guess;
            } else {
                tail = guess;
            }
        }
        lastGuess = guess;
        guess = (head + tail) / 2;
    }

    return -1;
}

int main(int argc, const char* argv[]) {
    std::vector<int> test = {4, 5, 6, 7, 8, 1, 2, 3};
    //std::vector<int> test = {1, 2, 3, 4, 5, 6, 7, 8};
    int target = 1;
    std::cout << search(test, target) << std::endl;
    return 0;
}
