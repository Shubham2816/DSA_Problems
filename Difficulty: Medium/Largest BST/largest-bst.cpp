/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    vector<int> how(Node* root)
    {
        // empty tree bst =0
        if(!root)
        return {1,0,INT_MAX,INT_MIN};
        if(!root->left&& !root->right)return {1,1,root->data,root->data};
        
        vector<int>l=how(root->left);
         vector<int>r=how(root->right);
        
        //current node grater than max in left and small than min in right
        if(l[0]&& r[0])
        {
            // it is a bst
            if(root->data>l[3]&&root->data<r[2])// l[3] mean compare to min r[3] compare  to max
            {int a=l[2];// min of left
            int b=r[3];// max of right
            if(a==INT_MAX) a=root->data;
             if(b==INT_MIN) b=root->data;
             return {1,l[1]+r[1]+1,a,b};
            }
        }
        return {0,max(l[1],r[1]),0,0};
    }
    
    int largestBst(Node *root)
    {
    	//Your code here
    vector<int>sol=how(root);// vector return means bst size min max
    return sol[1];
    	
    }
};
