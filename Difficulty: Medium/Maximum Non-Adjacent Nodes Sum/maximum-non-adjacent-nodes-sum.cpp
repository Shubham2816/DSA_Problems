/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    pair<int,int>how(Node*root)
    {
        if(root == NULL){
            pair<int,int>p=make_pair(0,0);
            return p;
        }
        
        pair<int,int>left=how(root->left);
        pair<int,int>right=how(root->right);
        
        pair<int,int>a;
        a.first = root->data + left.second + right.second;
        a.second = max(left.first,left.second) + max(right.first,right.second);
        
        return a;
        
    } 
    
   int getMaxSum(Node *root) 
    {
        pair<int,int>a=how(root);
        return max(a.first,a.second);
    }
};