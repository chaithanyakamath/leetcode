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
    vector<int> store;
    void inorder(TreeNode* root){
        if(!root)   return;

        inorder(root->left);
        store.push_back(root->val);
        inorder(root->right);
    }

    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);

        int n = store.size();
        TreeNode* temp = new TreeNode(store[0]);
        TreeNode* curr = temp;

        for(int i=1; i<n; i++){
            curr->right = new TreeNode(store[i]);
            curr = curr->right;
        }
        return temp;
    }
};