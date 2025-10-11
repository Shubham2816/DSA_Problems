/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  
    int sol=INT_MIN;
    int how(Node*root)
    {
        if(!root)return 0;
        
        int l=max(0,how(root->left));  int r=max(0,how(root->right));
        sol=max(sol,root->data+l+r);
        return root->data+max(l,r);
    }
  
    int findMaxSum(Node *root) {
        // code here
        //  sol=INT_MIN;
        how(root);
        return sol;
    }
};