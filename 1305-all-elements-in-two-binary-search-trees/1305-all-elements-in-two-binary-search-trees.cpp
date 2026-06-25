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
    void inorder(TreeNode* root, vector<int>& nums){
        if(!root)   return;

        inorder(root->left,nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> nums1, nums2;
        inorder(root1, nums1);
        inorder(root2, nums2);
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());

        return nums1;
    }
};