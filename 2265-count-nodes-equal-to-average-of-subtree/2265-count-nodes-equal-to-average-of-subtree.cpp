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
    int ans = 0;
    pair<int, int> dfs(TreeNode* root){
        if(!root)   return {0,0}; //root with no children

        auto lsub = dfs(root->left); // left subtree till leaf of left subtree
        auto rsub = dfs(root->right); // right subtree till leaf of right subtree

        int sum = lsub.first + rsub.first + root->val; // compute sum of each node's subtree along with its value
        int count = lsub.second + rsub.second + 1; // compute count of nodes in its subtree along with itself

        if(sum/count == root->val) ans++; // main comparision
        
        return{sum, count};
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};