// LC #572
#include <stdio.h>

class TreeNode
{
public:
    int val;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;

    TreeNode(int d) : val(d) {};
};

bool isSameTree(TreeNode* a, TreeNode* b) {
    if (!a && !b) return true;
    if ((!a | !b) || (a->val != b->val)) return false;
    return isSameTree(a->left, b) & isSameTree(a->right, b);
}

bool isSubtree(TreeNode* s, TreeNode* t) {
    if (!s) return false;
    if (isSameTree(s, t)) return true;
    return isSubtree(s->left, t) | isSubtree(s->right, t);
}


int main()
{
    printf("LeetCode #572\n");
}
