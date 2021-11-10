/*
Check if linked list is palindrome

Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.

Example 1:

Input:
N = 3
value[] = {1,2,1}
Output: 1
Explanation: The given linked list is
1 2 1 , which is a palindrome and
Hence, the output is 1.
Example 2:

Input:
N = 4
value[] = {1,2,3,4}
Output: 0
Explanation: The given linked list
is 1 2 3 4 , which is not a palindrome
and Hence, the output is 0.

Expected Time Complexity: O(N)
Expected Auxialliary Space Usage: O(1)  (ie, you should not use the recursive stack space as well)
*/

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
  
  Node* reverseHalfList(Node *head){
      Node *pre = NULL;
      Node *nxt = NULL;
      while(head != NULL){
          nxt = head->next;
          head->next = pre;
          pre =head;
          head = nxt;
      }
      return pre;
  }
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        if(head == NULL || head->next == NULL) return true;
        
        Node *f = head;
        Node *s = head;
        
        while(f->next != NULL && f->next->next != NULL){
            f=f->next->next;
            s=s->next;
        }
        
        s->next = reverseHalfList(s->next);
        s = s->next;
        
        while(s != NULL){
            if(head->data != s->data) return false;
            head = head->next;
            s=s->next;
        }
        
    return true;
    }
};
