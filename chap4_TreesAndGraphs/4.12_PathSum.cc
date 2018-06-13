// LC #437 Path Sum III
#include <stdio.h>

class TreeNode
{
public:
    int val;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
};

// LC #112 Path Sum I
bool hasPathSum(TreeNode* root, int sum) {
    if (!root) return false;
    if (root->val == sum && !root->left && !root->right) return true;
    sum -= root->val;
    return hasPathSum(root->left , sum) | hasPathSum(root->right, sum);
}

// LC #437 Path Sum III
void pathSum(vector<int>& vec, vector<int>::iterator elem, int sum, int currSum, int& nPath, unordered_map<int, int>& table) {
    if (elem == vec.end()) return;
    currSum += *elem;
    if (currSum == sum) nPath++;
    nPath += table[currSum - sum];

    table[currSum]++;
    pathSum(vec, ++elem, sum, currSum, nPath, table);
    table[currSum]--;
}

int pathSum(vector<int>& vec, vector<int>::iterator elem, int sum) {
    if (elem == vec.end()) return 0;
    int nPath = 0;
    int currSum = 0;
    unordered_map<int, int> table;  // currSum, nElem
    pathSum(vec, elem, sum, currSum, nPath, table);
    return nPath;
}


int main()
{
    printf("LeetCode Path Sum I-IV\n");

    srand(time(nullptr));
    vector<int> vec = {1, -1, 1, 2, -5, 8, -7, -6, 3, 6, -8};
    int sum = 3;

    for (auto &it : vec) {
        printf("%d ", it);
    }
    printf("\n");

    int res = pathSum(vec, vec.begin(), sum);

    printf("%d paths\n", res);
}
