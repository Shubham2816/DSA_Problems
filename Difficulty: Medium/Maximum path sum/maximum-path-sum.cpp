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
  
  int sum=INT_MIN;
  
  int solve(Node *root)
  {
      if(!root) return 0;
      
      int l= max(0, solve(root->left));
       int r= max(0, solve(root->right));
       
       sum=max(sum,l+r+root->data);
       
       return root->data+max(l,r);
  }
  
    int findMaxSum(Node *root) {
        // code here
        solve(root);
        return sum;
    }
};