//https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
   if(head==NULL||head->next==NULL)
          return head;
       Node *parentodd=new Node(-1);
       Node*parenteven=new Node(-1);
       Node* even=parenteven;
       Node*odd=parentodd;
       Node*cur=head;
       while(cur)
       {
           if(cur->data%2==0)
           {
               even->next=cur;
               even=even->next;
           }
           else
           {
               odd->next=cur;
               odd=odd->next;
           }
           cur=cur->next;
       }
       even->next=parentodd->next;
       odd->next=NULL;
       return parenteven->next;
    }
};
