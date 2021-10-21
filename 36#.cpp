class Solution
{
    public:
    Node* ans=NULL;
    int traverse(Node* root,int &n1,int &n2){
        if(root==NULL||ans!=NULL) return 0;
        int l=traverse(root->left,n1,n2);
        int r=traverse(root->right,n1,n2);
        if(root->data==n1||root->data==n2){
            if(l!=0) ans=root;
            else if(r!=0) ans=root;
            else return 1;
        }
         if(l!=0&&r!=0) ans=root;
        return max(l,r);
    }
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
        traverse(root,n1,n2);
       return ans;
    }
};
