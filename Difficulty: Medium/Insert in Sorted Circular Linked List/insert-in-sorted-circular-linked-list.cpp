/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
          Node* newNode = new Node(data);

    // Case 1: Empty list
    if (head == nullptr) {
        newNode->next = newNode;
        return newNode;
    }

    Node* curr = head;

    // Case 2: Insert before head (new min or max element)
    if (data < head->data) {
        // Find last node (tail)
        while (curr->next != head)
            curr = curr->next;
        curr->next = newNode;
        newNode->next = head;
        return newNode;  // New node becomes new head
    }

    // Case 3: Insert in correct sorted position
    while (curr->next != head && curr->next->data < data) {
        curr = curr->next;
    }

    // Insert after `curr`
    newNode->next = curr->next;
    curr->next = newNode;

    return head;
    }
};