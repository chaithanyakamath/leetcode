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
    int Msum = INT_MIN;
    int sum(TreeNode* root){
        if(root == nullptr) return 0;

        int lsum = sum(root->left);
        int rsum = sum(root->right);
        
        int opt1 = lsum+ rsum + root->val;
        int opt2 = max(lsum, rsum) + root->val;
        int opt3 = root->val;
        
        Msum = max({Msum, opt1, opt2, opt3});

        return max(opt2, opt3);
    }

    int maxPathSum(TreeNode* root) {
        sum(root);
        return Msum;
    }
};