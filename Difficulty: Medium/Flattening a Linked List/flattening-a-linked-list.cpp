/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
    // given     :  right pointer, bottom pointer , sorted in one direction

// have to keep merge function up so when we call it in flatten it should know that there is any merge function
    
Node* merge ( Node*a1, Node* a2) // taking two pointers represnting two sorted ll of bottom
{
    // but in case if any ll going is null we have to jump to next ll therfore
    if(a1==NULL)
    {
        return a2;
    }
    
     if(a2==NULL)
    {
        return a1;
    }
    
    // in order to return our answer in form of ll we have to dtore it 
    Node* ans;
    
    // now in order to check the order of data it is very necessary to compare and then use our merge function
    
    if(a1->data<a2->data)
    {
        ans=a1;
        ans->bottom=merge(a1->bottom,a2);
    }
    
    else
    {
        ans=a2;
        ans->bottom=merge(a1,a2->bottom);
    }
    
    ans->next=NULL;
    return ans;
}

    
Node *flatten(Node *root)
{
   /* if  the root is null or may be right of root is null in that case we have to submit the root */
   if ( root==NULL|| root->next ==NULL)
   {
       return root;
   }
   
   /*  if the root is not null then have to perform merge operation and sorting with it */
   return merge (root, flatten (root->next)); // using the recursion
}
};