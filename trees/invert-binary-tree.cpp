#include <stack>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        if(!root)
            return nullptr;

        stack<TreeNode*> s;
        s.push(root);

        while(!s.empty())
        {
            TreeNode *temp=s.top();
            s.pop();
            if(temp->left)
                s.push(temp->left);
            if(temp->right)
                s.push(temp->right);
            swap(temp->left, temp->right);
        }   
        return root; 
    }
};