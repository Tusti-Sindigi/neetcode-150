struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Time complexity = O(n)
// Space complexity = O(h)

class Solution 
{
public:
    int count=1;
    
    int goodNodes(TreeNode* root) 
    {
        dfs(root, root->val);
        return count;    
    }

    void dfs(TreeNode *root, int max)
    {
        if(!root)
            return;

        if(root->left)
        {   
            int next_max=max;
            if(root->left->val>=max)
            {
                count++;
                next_max=root->left->val;
            }    
            dfs(root->left, next_max);
        }
        if(root->right)
        {   
            int next_max=max;
            if(root->right->val>=max)
            {
                count++;
                next_max=root->right->val;
            }
            dfs(root->right, next_max);
        }
    }
};