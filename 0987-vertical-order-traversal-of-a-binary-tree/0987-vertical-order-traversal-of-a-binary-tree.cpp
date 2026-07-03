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
    void dfs(TreeNode* root, int col, int row, vector<tuple<int, int, int>> &store){
        if(!root)   return;
        store.emplace_back(col,row, root->val); // emplace_back() to push multiple attributes

        dfs(root->left, col-1, row+1, store);
        dfs(root->right, col+1, row+1, store);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int, int, int>> store; // col, row, root->val
        dfs(root, 0, 0, store); // (root, col, row, store)

        sort(store.begin(), store.end()); // sort lexicographically
        vector<vector<int>> ans;
        int prevCol = INT_MAX;
        for(auto[col, row, val] : store){
            if(prevCol != col){ // chcange the inner matrix - column lvl
                ans.push_back({}); // adds new column initially
                prevCol = col;
            }
            ans.back().push_back(val); // adding values to each column respectively
        }
        return ans;
    }
};