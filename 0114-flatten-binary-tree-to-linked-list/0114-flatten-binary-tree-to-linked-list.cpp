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
    TreeNode* prev;

    void preOrder(TreeNode* cur){
        if(!cur) return ;
        if(prev){ // to flatten 2 nodes
            prev->left = NULL;
            prev->right = cur;
        }

        TreeNode* r = cur->right; // right subtree for each node in each recursive call
        prev = cur;
        preOrder(cur->left); // left subtree
        preOrder(r); //right subtree
    }

    void flatten(TreeNode* root) {
        prev = NULL;
        preOrder(root);
    }
};