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

    TreeNode* build(vector<int> &nums, int left, int right){
        if(left > right)    return nullptr;

        int mid = left +(right - left)/2;
        TreeNode* roott = new TreeNode(nums[mid]);

        roott->left = build(nums, left, mid-1);
        roott->right = build(nums, mid+1, right);

        return roott;
    }

    TreeNode* balanceBST(TreeNode* root) {
       inorder(root);
       int n = store.size();
       sort(store.begin(), store.end());
       return build(store, 0, n-1);     
    }
};