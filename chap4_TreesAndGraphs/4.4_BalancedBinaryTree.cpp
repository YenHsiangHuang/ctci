// LC #110
#include <algorithm>
using namespace std;

//////////////////////////////////////////////////////////////////////////
class TreeNode
{
public:
    int data;
    TreeNode* parent = nullptr;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;

    TreeNode(int d) : data(d) {};
};
//////////////////////////////////////////////////////////////////////////

int getHeight(TreeNode* node) {
    if (node == nullptr) return 0;

    int lH = getHeight(node->left);
    int rH = getHeight(node->right);

    if (lH == -1 || rH == -1 || abs(lH-rH) > 1) return -1;

    return max(lH, rH) + 1;
}

bool isBalanced(TreeNode* root) {
    return (getHeight(root) == -1) ? false : true;
}

int main()
{
    // placeholder
    return 0;
}
