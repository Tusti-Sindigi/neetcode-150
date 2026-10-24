#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Time complexity = O(h) where h<n
// Space complexity = O(1)

// You can use the same logic but with recursion as well, but the space complexity would increase to O(h)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        TreeNode* temp=root;
        
        while(temp)
        {
            if(temp->val>p->val && temp->val>q->val)
                temp=temp->left;
            else if(temp->val<p->val && temp->val<q->val)
                temp=temp->right;
            else
                return temp;
        }
        return NULL;
    }
};