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
    int diff = 0;
    int maxAncestorDiff(TreeNode* root) {
        if(!root)   return 0;
        int minVal = root->val;
        int maxVal = root->val;
        chk(root, minVal, maxVal); // initializing main root val as both minimum n maximum

        return diff;
    }
    void chk(TreeNode* root, int minVal, int maxVal){
        if(!root)   return;

        diff = max(diff, max(abs(minVal - root->val), abs(maxVal - root->val))); // compute max diff  btwn ancestors having min/max val with curr root val 

        minVal = min(minVal, root->val);
        maxVal = max(maxVal, root->val);// updating min n max val val if found accordingly

        chk(root->left, minVal, maxVal);
        chk(root->right, minVal, maxVal);
        // catch is min n max val can be held by anyone in ancestor
    }
};