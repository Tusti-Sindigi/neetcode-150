#include <algorithm>
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

class Solution 
{
public:

    int goodNodes(TreeNode* root) 
    {
        int count=0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, -INT_MAX});

        while(!q.empty())
        {
            auto [temp, maxi]=q.front();
            q.pop();

            if(temp->val>=maxi)
                count++;

            if(temp->left)
                q.push({temp->left, max(temp->val, maxi)});
            if(temp->right)
                q.push({temp->right, max(temp->val, maxi)});
        }
        return count;
    }
};