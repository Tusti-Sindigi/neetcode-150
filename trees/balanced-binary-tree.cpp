// Worst case time complexity = O(N^2)
// Worst case space complexity = O(N)

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

class Solution {
public:
    bool isBalanced(TreeNode* root) 
    {
        if(!root)
            return true;
        
        bool l=isBalanced(root->left);
        bool r=isBalanced(root->right);

        if(!(l && r))
            return false;
        
        int left=height(root->left);
        int right=height(root->right);

        int diff=abs(left-right);

        return (diff==1 || diff==0)? true: false;
    }

    int height(TreeNode *root)
    {
        if(!root)
            return 0;

        return 1+max(height(root->left), height(root->right));
    }
};