// LC #518
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include "printer.h"
#include "timer.h"

// DP solution, this is insane......
int changeDP(int amount, std::vector<int>& coins) {
    std::vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int coin : coins) {
        for (int i = coin; i <= amount; ++i) {
            dp[i] += dp[i - coin];
        }
    }

    return dp[amount];
}

int changeDP(int amount, std::vector<int>&& coins) {
    return changeDP(amount, coins);
}

// Recursive solution, much slower and takes more space
int changeRecursive(int amount, std::vector<int>& coins, int coinsBack,
           std::multimap<int, std::pair<int, int>>& prevCombination) {
    if (amount == 0) return 1;
    if (coinsBack == 0) return amount % coins[0] == 0;

    auto prevAns = prevCombination.equal_range(amount);
    for (auto it = prevAns.first; it != prevAns.second; ++it) {
        if (it->second.first != coinsBack) continue;
        return it->second.second;
    }

    int res = 0;
    for (int i = 0; i < amount / coins[coinsBack] + 1; ++i)
        res += changeRecursive(amount - i * coins[coinsBack], coins, coinsBack - 1,
                      prevCombination);

    prevCombination.insert(
        std::make_pair(amount, std::pair<int, int>(coinsBack, res)));

    return res;
}

int changeRecursive(int amount, std::vector<int>& coins) {
    if (coins.empty()) return 0;
    std::multimap<int, std::pair<int, int>>
        prevCombination;  // <amount, <coinsBack, answer>>
    std::sort(coins.begin(), coins.end());
    return changeRecursive(amount, coins, coins.size() - 1, prevCombination);
}

int changeRecursive(int amount, std::vector<int>&& coins) {
    return changeRecursive(amount, coins);
}

int main(int argc, const char *argv[])
{
    tic(us, "Recursive: ");
    std::cout << changeRecursive(1000, std::vector<int>{3,5,7,8,9,10,11}) << std::endl;
    toc();

    tic(us, "DP:        ");
    std::cout << changeDP(1000, std::vector<int>{3,5,7,8,9,10,11}) << std::endl;
    toc();
    return 0;
}
