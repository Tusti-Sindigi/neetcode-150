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

//  Time complexity = O(n)
//  Space complexity = O(n)

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> res;

        if(!root)
        return res;

        queue<TreeNode*> que;
        que.push(root);
        
        while(!que.empty())
        {
            int i=que.size();
            vector<int> v;

            while(i--)
            {
                TreeNode* temp=que.front();
                que.pop();

                if(temp)
                {
                    v.push_back(temp->val);
                    que.push(temp->left);
                    que.push(temp->right);
                }
            }

            if(!v.empty())
                res.push_back(v);
        }
        return res;
    }
};