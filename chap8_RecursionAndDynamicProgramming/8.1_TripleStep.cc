// LC #70
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

// Bottom-up without extra space
int countWayBottomUpNoExtraSpace(int n) {
    if (n < 3) return n;
    if (n == 3) return 4;

    int tmp0, tmp1 = 1, tmp2 = 2, tmp3 = 4;

    for (int i = 4; i <= n; i++) {
        tmp0 = tmp1 + tmp2 + tmp3;
        tmp1 = tmp2;
        tmp2 = tmp3;
        tmp3 = tmp0;
    }
    return tmp0;
}

int main(int argc, const char* argv[]) {
    tic(us);
    std::cout << countWayRecursive(20) << std::endl;
    toc();
    tic(us);
    std::cout << countWayMemoi(20) << std::endl;
    toc();
    tic(us);
    std::cout << countWayBottomUp(20) << std::endl;
    toc();
    tic(us);
    std::cout << countWayBottomUpNoExtraSpace(20) << std::endl;
    toc();
}
