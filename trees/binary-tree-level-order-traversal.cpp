#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//  Time complexity = O(n)
//  Space complexity = O(n)

class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        dfs(root, 0);
        return res;
    }

    void dfs(TreeNode* root, int ht)
    {
        if(!root)
            return;

        if(res.size()==ht)
            res.push_back(vector<int>());

        res[ht].push_back(root->val);
        dfs(root->left, ht+1);
        dfs(root->right, ht+1);
    }
};