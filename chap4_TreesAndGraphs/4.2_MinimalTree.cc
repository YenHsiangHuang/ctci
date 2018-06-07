// LC #108
#include <vector>
#include <cmath>

using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode* parent = nullptr;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;

    TreeNode(int d) : data(d) {};
};

TreeNode* createMinimalBST(vector<int>& sortedValue, int start, int end) {
    if (start > end) return nullptr;

    int mid = start + (end-start)/2;
    TreeNode* node = new TreeNode(sortedValue[mid]);
    node->left = createMinimalBST(sortedValue, start, mid-1);
    node->right = createMinimalBST(sortedValue, mid+1, end);
    return node;
}

TreeNode* createMinimalBST(vector<int>& sortedValue) {
    return createMinimalBST(sortedValue, 0, sortedValue.size()-1);
}

int main()
{
    vector<int> sortedValue = {0, 1, 2, 3, 4};
    TreeNode* tree = createMinimalBST(sortedValue);
}
