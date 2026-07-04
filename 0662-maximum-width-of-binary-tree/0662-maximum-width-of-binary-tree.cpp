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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root,0});
        int ans = 0;

        while(!q.empty()){
            int size = q.size();
            vector<int> store;

            while(size--){
                TreeNode* curr = q.front().first;
                unsigned long long n = q.front().second;
                q.pop();

                store.push_back(n); 

                if(curr->left)  q.push({curr->left, 2*n+1});
                if(curr->right)  q.push({curr->right, 2*n+2});
            }
            int m = store.size();
            ans = max(ans,store[m-1]-store[0]+1);
        }
        return ans;
    }
};