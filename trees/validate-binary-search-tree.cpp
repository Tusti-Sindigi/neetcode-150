#include <climits> // or <algorithm> which includes <climits> itself
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Time complexity = O(n)
// Space complexity = O(n)

class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {
        return dfs(root, LONG_MIN, LONG_MAX);
    }

    bool dfs(TreeNode* root, long minimum, long maximum)
    {
        if(!root)
            return true;

        if(!(root->val>minimum && root->val<maximum))
            return false;

        return dfs(root->left, minimum, root->val) && dfs(root->right, root->val, maximum);
    }
};