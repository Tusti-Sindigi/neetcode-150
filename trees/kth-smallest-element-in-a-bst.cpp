struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Best case time complexity = O(log(n)+k) --> when tree is balanced
// Worst case time complexity = O(n) --> when tree is skewed and k=n
// Best case space complexity = O(log(n)) --> tree is balances
// Worst case space complexity = O(n) --> tree is skewed

class Solution {
public:
    int c=1;

    int kthSmallest(TreeNode* root, int k) 
    {
        return dfs(root, k);    
    }

    int dfs(TreeNode *root, int k)
    {
        if(root->left)
        {
            int res=dfs(root->left, k);

            if(res!=-1)
                return res;
        }    
        
        if(c==k)
            return root->val;
        else
            c++;

        if(root->right)
            return dfs(root->right, k);
        
        return -1;
    }
};