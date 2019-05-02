// LC #102
#include <vector>
#include <queue>
#include <cmath>

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
//////////////////////////////////////////////////////////////////////////

vector<vector<int>> createLevelOrderList(TreeNode* root) {
    if (root == nullptr) return vector<vector<int>> {};

    queue<TreeNode*> q;
    vector<vector<int>> res;

    q.push(root);
    q.push(nullptr);
    res.resize(1);
    while (!q.empty()) {
        TreeNode* currNode = q.front();
        q.pop();
        if (currNode != nullptr) {
            res.back().push_back(currNode->data);
            if (currNode->left) q.push(currNode->left);
            if (currNode->right) q.push(currNode->right);
        } else {
            res.resize(res.size()+1);
            if (!q.empty()) q.push(nullptr);
        }
    }

    res.pop_back();
    return res;
}

void printLevelOrder(vector<vector<int>>& levelOrder) {
    for (auto &v1 : levelOrder) {
        for (auto &v2 : v1) {
            printf("%d ", v2);
        }
        printf("\n");
    }
}



int main()
{
    vector<int> sortedValue;
    for (int i = 0; i < 20; i++) {
        sortedValue.push_back(i);
    }
    TreeNode* tree = createMinimalBST(sortedValue);

    vector<vector<int>> levelOrder = createLevelOrderList(tree);
    printLevelOrder(levelOrder);
}
