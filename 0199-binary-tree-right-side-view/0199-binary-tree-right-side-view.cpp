/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans; 
        if(!root)   return ans;
        queue<TreeNode*> qu;
        qu.push(root);

        while(!qu.empty()){
            int n = qu.size();
            for(int i=0; i<n; i++){
                TreeNode* cur = qu.front();
                qu.pop();
                if(i == n-1)    ans.push_back(cur->val);
                if(cur->left)   qu.push(cur->left);
                if(cur->right)   qu.push(cur->right);
            }
        }
        return ans;
    }
};