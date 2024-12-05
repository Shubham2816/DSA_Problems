/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // ListNode* prev = nullptr;  // To keep track of the previous node
        // ListNode* curr = head;     // To traverse the list
        // ListNode* next = nullptr;  // To keep track of the next node
        
        // while (curr != nullptr) {
        //     next = curr->next;  // Save the next node
        //     curr->next = prev;  // Reverse the current node's pointer
        //     prev = curr;        // Move prev to the current node
        //     curr = next;        // Move to the next node
        // }
        
        // return prev;  // prev will be the new head of the reversed list






        ListNode* prev =NULL;
        ListNode* curr= head;
        ListNode* neext=NULL;

        while(curr!=NULL)
        {
            neext=curr->next;
            curr->next=prev;
            prev=curr;
            curr=neext;
        }
        return prev;
    }
};
