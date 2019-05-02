#include <vector>
#include <cmath>
using namespace std;

// Helpers and Definition ///////////////////////////////////////////
class TreeNode
{
public:
    int data;
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

inline void printVec(vector<int>& vec) {
    for (auto &elem : vec) printf("%d ", elem);
    printf("\n");
}

inline void printVecVec(vector<vector<int>>& vv) {
    for (auto &v : vv) printVec(v);
}


/////////////////////////////////////////////////////////////////////
void weave(vector<int>& vec1, vector<int>& vec2, vector<int>& prefix, vector<vector<int>>& res) {
    if (vec1.empty() | vec2.empty()) {
        res.push_back(prefix);
        if (!vec1.empty()) res.back().insert(res.back().end(), vec1.begin(), vec1.end());
        if (!vec2.empty()) res.back().insert(res.back().end(), vec2.begin(), vec2.end());
        return;
    }

    prefix.push_back(vec1.front());
    vec1.erase(vec1.begin());
    weave(vec1, vec2, prefix, res);
    vec1.insert(vec1.begin(), prefix.back());
    prefix.pop_back();

    prefix.push_back(vec2.front());
    vec2.erase(vec2.begin());
    weave(vec1, vec2, prefix, res);
    vec2.insert(vec2.begin(), prefix.back());
    prefix.pop_back();
}

vector<vector<int>> weave(vector<int>& vec1, vector<int>& vec2) {
    vector<int> prefix;
    vector<vector<int>> res;
    weave(vec1, vec2, prefix, res);
    return res;
}

vector<vector<int>> findBSTSequence(TreeNode* root) {
    if (!root) return vector<vector<int>> ();

    vector<vector<int>> leftRes  = findBSTSequence(root->left );
    vector<vector<int>> rightRes = findBSTSequence(root->right);
    vector<vector<int>> res;

    if (!leftRes.empty() & !rightRes.empty()) {
        for (auto &vec1 : leftRes) {
            for (auto &vec2 : rightRes) {
                auto tmp = weave(vec1, vec2);
                res.insert(res.end(),
                           make_move_iterator(tmp.begin()),
                           make_move_iterator(tmp.end()));
            }
        }
    }
    else if (!leftRes .empty()) res = leftRes ;
    else if (!rightRes.empty()) res = rightRes;

    if (res.empty()) res.push_back(vector<int> (1, root->data));
    else             for (auto &vec : res) vec.insert(vec.begin(), root->data);
    return res;
}


int main()
{
    vector<int> sortedValue;
    for (int i = 1; i < 6; i++) {
        sortedValue.push_back(i);
    }
    printf("\n");

    TreeNode* tree = createMinimalBST(sortedValue);

    auto res = findBSTSequence(tree);
    printVecVec(res);
}
