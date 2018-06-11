// LC #236
#include <stdio.h>

class TreeNode
{
public:
    int data;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
};

TreeNode* firstCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return nullptr;
    if (root == p | root == q) return root;

    TreeNode* leftNode  = firstCommonAncestor(root->left , p, q);
    TreeNode* rightNode = firstCommonAncestor(root->right, p, q);

    // Can I replace the following three lines with this?
    //return !left ? right : !right ? left : root;
    if ((leftNode != nullptr) ^ (rightNode != nullptr)) return leftNode ? leftNode : rightNode;
    if ((leftNode != nullptr) & (rightNode != nullptr)) return root;
    return nullptr;
}

int main()
{
    printf("LeetCode #236\n");
}
