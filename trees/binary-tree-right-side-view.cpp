//  Time complexity = O(n)
//  Space complexity = O(n)

#include <vector>
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

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> res;

        if(!root)
            return res;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            vector<int> v;
            int s=q.size();

            while(s--)
            {
                TreeNode *temp=q.front();
                q.pop();

                if(temp)
                {
                    v.push_back(temp->val);
                    q.push(temp->left);
                    q.push(temp->right);
                }
            }
            if(!v.empty())
                res.push_back(v[v.size()-1]);
        }
        return res;
    }
};