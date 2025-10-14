/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    int nodeSum(Node* root, int l, int r) {
        // code here
        if(root==NULL)return 0;
        
        int shu=0;
        if (root->data >= l && root->data <= r) {
            shu += root->data;
        }
        if (root->data > l) {
            shu += nodeSum(root->left, l, r);
        }
        if (root->data < r) {
            shu += nodeSum(root->right, l, r);
        }
        return shu;
    }
};
