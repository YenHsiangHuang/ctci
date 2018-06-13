// LC #437 Path Sum III
#include <stdio.h>
#include <vector>
#include <unordered_map>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
};

/**
    LC #112 Path Sum I

    Given a binary tree and a sum, determine if the tree has a root-to-leaf
    path such that adding up all the values along the path equals the given sum.
 */
bool hasPathSum(TreeNode* root, int sum) {
    if (!root) return false;
    if (root->val == sum && !root->left && !root->right) return true;
    sum -= root->val;
    return hasPathSum(root->left , sum) | hasPathSum(root->right, sum);
}

/**
    LC #113 Path Sum II

    Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
 */
void pathSumHelperII(TreeNode* root, int sum, int currSum, vector<int>& path, vector<vector<int>>& res) {
    if (!root) return;

    currSum += root->val;
    path.push_back(root->val);
    if (!root->left && !root->right && currSum == sum) res.push_back(path);

    pathSumHelperII(root->left , sum, currSum, path, res);
    pathSumHelperII(root->right, sum, currSum, path, res);

    path.pop_back();
}

vector<vector<int>> pathSumII(TreeNode* root, int sum) {
    if (!root) return vector<vector<int>> ();

    int currSum = 0;
    vector<int> path;
    vector<vector<int>> res;
    pathSumHelperII(root, sum, currSum, path, res);
    return res;
}


/**
    LC #437 Path Sum III

    You are given a binary tree in which each node contains an integer value.
    Find the number of paths that sum to a given value.
    The path does not need to start or end at the root or a leaf, but it must
    go downwards (traveling only from parent nodes to child nodes).
    The tree has no more than 1,000 nodes and the values are in the range
    -1,000,000 to 1,000,000.
 */
void pathSumHelperIII(TreeNode* root, int sum, int currSum, int& nPath, unordered_map<int, int>& runningSum) {
    if (!root) return;

    currSum += root->val;
    if (currSum == sum) nPath++;
    nPath += runningSum[currSum-sum];

    runningSum[currSum]++;
    pathSumHelperIII(root->left , sum, currSum, nPath, runningSum);
    pathSumHelperIII(root->right, sum, currSum, nPath, runningSum);
    runningSum[currSum]--;
}

int pathSumIII(TreeNode* root, int sum) {
    if (!root) return 0;

    int nPath = 0;
    int currSum = 0;
    unordered_map<int, int> runningSum;
    pathSumHelperIII(root, sum, currSum, nPath, runningSum);
    return nPath;
}

int main()
{
    printf("LeetCode Path Sum I-IV\n");
}
