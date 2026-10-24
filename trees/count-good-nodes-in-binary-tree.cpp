#include <algorithm>
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

class Solution 
{
public:
    int count=1;

    int goodNodes(TreeNode* root) 
    {
        return dfs(root, root->val);   
    }

    int dfs(TreeNode *root, int maxi)
    {
        if(!root)
            return 0;

        int res=0;
        if(root->val>=maxi)
            res=1;

        maxi=max(root->val, maxi);
        
        res+=dfs(root->left, maxi);
        res+=dfs(root->right, maxi);
        
        return res;
    }
};