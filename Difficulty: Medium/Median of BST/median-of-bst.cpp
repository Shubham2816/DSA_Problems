/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
     void findInorder(Node* root,vector<int>&ans){
      if(!root) return;
      findInorder(root->left,ans);
      ans.push_back(root->data);
      findInorder(root->right,ans);
  }
    int findMedian(Node* root) {
        // Code here
        vector<int>ans;
        findInorder(root,ans);
        int start=0;
        int end=ans.size();
        int mid=start+(end-start)/2;
        if(end%2==0){
            return ans[mid-1];
        }
        else{
            return ans[mid];
        }
        return 0;
    }
};