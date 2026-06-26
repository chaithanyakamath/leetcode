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
class BSTIterator {
public:
    stack<TreeNode*> st; // vector uses 0(n), since we need 0(h) we use stack n perform partial inorder traversal
    void iterate(TreeNode* root){
        while(root){
            st.push(root);
            root = root->left; //this is partial inorder traversal to traverse one part of subtree till end
        }
    }

    BSTIterator(TreeNode* root) {
        iterate(root);
    }

    int next() {
        TreeNode* curr = st.top();
        st.pop();
        iterate(curr->right); //when u reach end of one part of the  subtree chk for current nodes right subtree
        return curr->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */