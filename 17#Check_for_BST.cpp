/*
Check For BST

Given the root of a binary tree. Check whether it is a BST or not.
Note: We are considering that BSTs can not contain duplicate Nodes.
A BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

Input:
   2
 /    \
1      3
Output: 1 
Explanation: 
The left subtree of root node contains node 
with key lesser than the root node’s key and 
the right subtree of root node contains node 
with key greater than the root node’s key.
Hence, the tree is a BST.
Example 2:

Input:
  2
   \
    7
     \
      6
       \
        5
         \
          9
           \
            2
             \
              6
Output: 0 
Explanation: 
Since the node with value 7 has right subtree 
nodes with keys less than 7, this is not a BST.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the BST).


*/

class Solution
{
    public:
    vector<int> a;
   void check(Node* root){
       if(root == NULL) return;
       
       check(root->left);
       a.push_back(root->data);
       check(root->right);
   }
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) 
    {
        // Your code here
        check(root);
       for(int i = 1;i < a.size();i++){
           if(a[i] <= a[i-1]) return false;
       }
       return true;
    }
};
