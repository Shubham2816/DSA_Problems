/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = NULL;
    }
};
*/

class Solution {
  public:
    bool isPalindrome(Node *head) {
        //  code here
        Node *temp = head;
        string s = "";
        while(temp!=NULL){
            s+=temp->data;
           temp = temp->next;
        }
        for(int i=0,j=s.length()-1;j>=0;j--,i++)
       {
           if(s[i] != s[j])
           {
               return false;
           }
       }
       return true;
    }
};