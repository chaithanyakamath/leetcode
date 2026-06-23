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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2)    return nullptr;
        if(!root1 || !root2)    return root1 ? root1 : root2;
        
        queue<TreeNode*> q1, q2;
        q1.push(root1);
        q2.push(root2);

        while(!q1.empty() && !q2.empty()){
            int n1 = q1.size();
            int n2 = q2.size();

            TreeNode* cur1 = q1.front();
            TreeNode* cur2 = q2.front();
            q1.pop(); q2.pop();

            cur1->val += cur2->val;

            if(!cur1->left && cur2->left) cur1->left = cur2->left;
            else if(cur1->left && cur2->left){
                q1.push(cur1->left);
                q2.push(cur2->left);
            }

            if(!cur1->right && cur2->right) cur1->right = cur2->right;
            else if(cur1->right && cur2->right){
                q1.push(cur1->right);
                q2.push(cur2->right);
            }
        }
        return root1;
    }
};