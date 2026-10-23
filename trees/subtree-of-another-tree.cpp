// Time complexity = O(m*n)
// Space complexity = O(m+n)

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        if(!root)
            return false;

        if(root->val==subRoot->val)
            if(sameTree(root, subRoot))
                return true;
        
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool sameTree(TreeNode* startRoot, TreeNode* subRoot)
    {
        if(!startRoot && !subRoot)
            return true;
        else if((startRoot && subRoot) && (startRoot->val==subRoot->val))
            return sameTree(startRoot->left, subRoot->left) && sameTree(startRoot->right, subRoot->right);
        else
            return false;
    }
};