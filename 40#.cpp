class Solution {
  public:
    bool isHeap(struct Node* tree) {
        // code here
        queue<pair<Node*,int>>q;
       q.push({tree,INT_MAX});
       bool pre=true;
       while(!q.empty()){
           Node* temp=q.front().first;
           int maxi=q.front().second;
           
           q.pop();
           
           if(temp!=NULL && temp->data>maxi){
               return false;
           }
           if(temp==NULL){
               pre=false;
           }
           else{
               if(pre==false){
                   return false;
               }
                  q.push({temp->left,temp->data});
               
               q.push({temp->right,temp->data});
           }
       }
       return true;
    }
};
