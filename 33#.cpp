class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
       Node curr=head;
       Node next=null;
       Node pre=head;
       Node even=head;
       while(curr!=null&&curr.next!=null){
           if(curr.next.data%2==0){
               even=curr.next;
               next=curr.next.next;
               curr.next=next;
               even.next=pre;
               pre=even;
           }
           else curr=curr.next;
       }
       return even;
    }
};
