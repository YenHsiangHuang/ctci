/**
   A child is running up a staircase with n steps and can hop either 1 setp, 2
   steps, or 3 steps at a time. Implement a method to count how many possible
   ways the child can run up the stairs.
 */
#include <iostream>
#include <vector>
#include "timer.h"

// Recursive solution
int countWayRecursive(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 4;

    return countWayRecursive(n - 1) +
           countWayRecursive(n - 2) +
           countWayRecursive(n - 3);
}


// Memoization solution
int countWayMemoi(int n, std::vector<int>& memo) {
    if (memo[n] != 0) return memo[n];

    memo[n] = countWayMemoi(n-1, memo) +
              countWayMemoi(n-2, memo) +
              countWayMemoi(n-3, memo);
    return memo[n];
}

int countWayMemoi(int n) {
    std::vector<int> memo = {0, 1, 2, 4};
    if (n < 4) return memo[n];
    memo.resize(n + 1);
    return countWayMemoi(n, memo);
}

// Bottom-up solution
int countWayBottomUp(int n) {
    std::vector<int> memo = {0, 1, 2, 4};
    if (n < 4) return memo[n];
    memo.resize(n + 1);

    for (int i = 4; i <= n; i++)
        memo[i] = memo[i - 1] + memo[i - 2] + memo[i - 3];

    return memo[n];
}

int main(int argc, const char* argv[]) {
    int testCase = 8;
    tic();
    std::cout << countWayRecursive(20) << std::endl;
    toc();
    tic();
    std::cout << countWayMemoi(20) << std::endl;
    toc();
    tic();
    std::cout << countWayBottomUp(20) << std::endl;
    toc();
}
