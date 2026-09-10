class Solution {
public:
    int count = 0;

    int solve(TreeNode* root, int &rootCount){
        if(!root){
            rootCount = 0;
            return 0;
        }

        int lrootCount = 0;
        int rrootCount = 0;

        int l = solve(root->left, lrootCount);
        int r = solve(root->right, rrootCount);

        rootCount = lrootCount + rrootCount + 1;

        int sum = root->val + l + r;
        int avg = sum / rootCount;

        if(avg == root->val)
            count++;

        return sum;
    }

    int averageOfSubtree(TreeNode* root) {
        if(!root)
            return 0;

        int rootCount = 0;
        solve(root, rootCount);

        return count;
    }
};