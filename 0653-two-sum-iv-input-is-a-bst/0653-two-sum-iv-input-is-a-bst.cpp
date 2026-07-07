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

        return;
    }
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        int n = store.size();
        if(n == 1)  return false;

        int l = 0, r = n-1;
        while(l<r){
            int sum = store[l] + store[r];
            if(sum == k)    return true;

            if(sum > k)    r--;
            else   l++;
        }
        return false;
    }
};