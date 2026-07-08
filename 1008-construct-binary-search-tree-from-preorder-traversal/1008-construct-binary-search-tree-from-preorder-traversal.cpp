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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        TreeNode* ptr = root;
        TreeNode* lastPopped = nullptr;

        stack<TreeNode*> st;
        st.push(root);

        int n = preorder.size();
            for(int i=1; i<n; i++){
                TreeNode* curr = new TreeNode(preorder[i]);

                if(preorder[i] < st.top()->val){
                    st.top()->left = curr; // making curr node as left child of stack top
                }
                else{
                    TreeNode* popp = nullptr;
                    while(!st.empty() && st.top()->val < preorder[i]){
                        popp = st.top();
                        st.pop();
                    }
                    popp->right = curr;
                }
                st.push(curr);//pushing to stack irrespective of if n else
            }
        return root;
    }
};