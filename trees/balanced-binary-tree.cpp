// Using bottom up approach

// Worst case time complexity = O(n)
// Best case time complexity = O(log(n))

// Worst case space complexity = O(h)
// Best case space complexity = O(n)

#include <algorithm>
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

class Solution {
public:
    bool isBalanced(TreeNode* root) 
    {
        return dfs(root)[0]==1;
    }

    vector<int> dfs(TreeNode *root)
    {
        if(!root)
            return {1, 0};

        vector<int> left=dfs(root->left);
        vector<int> right=dfs(root->right);

        int balanced=(left[0]==1 && right[0]==1) && abs(left[1]-right[1])<=1;
        int ht=1+max(left[1], right[1]);

        return {balanced? 1: 0, ht};
    }
};