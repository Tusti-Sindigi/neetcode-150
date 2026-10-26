#include <climits> // or <algorithm> which includes <climits> itself
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

class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {
        queue<tuple<TreeNode*, long, long>> q;
        q.push({root, LONG_MIN, LONG_MAX});

        while(!q.empty())
        {
            auto [temp, minimum, maximum]=q.front();
            q.pop();

            if(!(temp->val>minimum && temp->val<maximum))
                return false;

            if(temp->left)
                q.push({temp->left, minimum, temp->val});

            if(temp->right)
                q.push({temp->right, temp->val, maximum});
        }

        return true;
    }
};