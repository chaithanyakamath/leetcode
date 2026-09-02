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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<TreeNode*> qu;
        qu.push(root);
        int lvl = 0;

        while(!qu.empty()){
            int n = qu.size();
            lvl++;

            while(n--){
                TreeNode* cur = qu.front();
                qu.pop();
                if(cur->left)   qu.push(cur->left);
                if(cur->right)   qu.push(cur->right);
            }
        }
        return lvl;
    }
};