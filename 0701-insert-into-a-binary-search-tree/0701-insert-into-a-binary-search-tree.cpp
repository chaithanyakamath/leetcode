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
    // void chk(TreeNode* root, int val){
    //     // if(!root)   return;
    //     if(root->val < val){
    //         root = root->left;
    //     }
    //     else root = root->right;

    //     TreeNode* ans = new TreeNode(val);
    //     if(root->val >  val)    root->left = ans;
    //     else root->right = ans;
    //     return;
    // }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr) return new TreeNode(val);

        if(root->val > val)     root->left = insertIntoBST(root->left, val);
        else    root->right = insertIntoBST(root->right, val);

        return root;
    }
};