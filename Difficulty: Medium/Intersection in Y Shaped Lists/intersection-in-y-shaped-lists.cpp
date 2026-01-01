/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        //  Code Here
         Node* t= head1;
    Node* r= head2;
    
    int c=0,d=0;
    
    while(t)
    {
        c++;
        t=t->next;
    }
    
    
    while(r)
    {
        d++; 
        r=r->next;
    }
    
   
    t=head1;
    r=head2;
    
    if(c>d)
    {
        int f=c-d;
        
        while(f--)
        {
            t=t->next;
        }
    }
    
    else
    if(d>c)
    {
        int e=d-c;
        
        while(e--)
        {
            r=r->next;
        }
    }
    
    while(t!=r)
    {
        t=t->next;
        r=r->next;
    }
    return t;
    }
};