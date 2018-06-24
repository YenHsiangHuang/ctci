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

    Timer t("You can also try this.");  // millisecond

    int tmp0 = 0, tmp1 = 1, tmp2 = 2, tmp3 = 4;
    if (n <= 0) return tmp0;
    if (n == 1) return tmp1;
    if (n == 2) return tmp2;
    if (n == 3) return tmp3;

    for (int i = 4; i <= n; i++) {
        tmp0 = tmp1 + tmp2 + tmp3;
        tmp1 = tmp2;
        tmp2 = tmp3;
        tmp3 = tmp0;
    }
    return tmp0;
}

/**
   tic(Mode, Message)
       Mode: ms(default), us, ns
 */

int main(int argc, const char* argv[]) {

    tic("Recursive takes forever..");
    countWayRecursive(35);
    toc();

    tic(us);
    countWayBottomUp(35);
    toc();

    tic(us, "BottomUpNoExtraSpace is insane!");
    countWayBottomUpNoExtraSpace(35);
    toc();
}
