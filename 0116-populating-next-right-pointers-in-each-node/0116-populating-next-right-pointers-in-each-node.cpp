/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)   return nullptr;
        // Node* ptr = root;
        // queue<Node*> qu;
        // qu.push(root);

        // while(!qu.empty()){
        //     int n = qu.size();
        //     for(int i=0; i<n-1; i++){
        //         Node* curr = qu.front();
        //         qu.pop();
        //     }
        // }
        if(root->left) root->left->next = root->right; // connecting at lvl 0 where there r 2 childrens
        if(root->right && root->next)   root->right->next = root->next->left;

        connect(root->left);
        connect(root->right);

        return root;
    }
};