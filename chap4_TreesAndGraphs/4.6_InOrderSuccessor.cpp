// LC #285 (Locked)
//     Assume a node does not know its parent
//     TreeNode* inOrderSuccessor(TreeNode* root, TreeNode* node)

// HackerRank Tree: In Order Traversal
//     Same assumption as LC

// CtCI
//     Assume a node knows its parent
//     TreeNode* inOrderSuccessor(TreeNode* node)
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


// Test Cases
#define Tree50
//#define TreeNull


///////////////////////////////////////////////////////////////////////////////
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
///////////////////////////////////////////////////////////////////////////////

TreeNode* leftMost(TreeNode* node) {
    if (!node) return nullptr;
    while (node->left) node = node->left;
    return node;
}

// LC
// Very clean answer but hard to come up with
TreeNode* inOrderSuccessor(TreeNode* root, TreeNode* target) {
    if (!root || !target) return nullptr;
    if (target->right) return leftMost(target->right);  // trivial part

    TreeNode* currNode = root;
    TreeNode* res = nullptr;
    while (currNode) {
        if (currNode->data > target->data) {
            res = currNode;
            currNode = currNode->left;
        } else {  // currNode->data < target->data
            currNode = currNode->right;
        }
    }
    return res;
}

/*
TreeNode* inOrderSuccessor(TreeNode* root, TreeNode* node) {
    if (!root || !node) return nullptr;

    if (node->right) return leftMost(node->right);

    // Find node p that go left once + all right to reach this node, return p
    // use BFS
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* currNode = q.front();
        q.pop();
        if (currNode->left ) q.push(currNode->left );
        if (currNode->right) q.push(currNode->right);
        // check if currNode is the first right-parent of target node
        if (isFirstRightParent(currNode, node)) return currNode;
    }
}

bool isFirstRightParent(TreeNode* node, TreeNode* target) {
    if (!node || !node->left) return false;
    if (node->left == target) return true;
    node = node->left;
    while (node->right) {
        if (node->right == target) return true;
    }
    return false;
}
*/


// CtCI
TreeNode* inOrderSuccessor(TreeNode* node) {
    if (!node) return nullptr;

    if (node->right) return leftMost(node->right);

    // Go up until go up and right
    while (node->parent) {
        TreeNode* child = node;
        node = node->parent;
        if (node->left == child) return node;
    }
    return nullptr;
}




int main()
{
#ifdef Tree50
    cout << "50" << endl;
    vector<int> sortedValue;
    for (int i = 0; i < 50; i++) {
        sortedValue.push_back(i);
    }
#endif
#ifdef TreeNull
    cout << "Null" << endl;
    vector<int> sortedValue;
#endif


    TreeNode* root = createMinimalBST(sortedValue);


}
