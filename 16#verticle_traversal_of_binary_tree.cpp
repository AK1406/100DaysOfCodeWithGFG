/*
Verticle Traversal of Binary Tree

Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

Example 1:

Input:
           1
         /   \
       2       3
     /   \   /   \
   4      5 6      7
              \      \
               8      9           
Output: 
4 2 1 5 6 3 8 7 9 
Explanation:

Example 2:

Input:
       1
    /    \
   2       3
 /    \      \
4      5      6
Output: 4 2 1 5 3 6

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

*/

class Solution
{
    public:
   vector<int> ans;
   map<int,vector<int>> m;
   queue<pair<Node*,int>> q;
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
         q.push({root,0});
       while(!q.empty()){
           Node* temp = q.front().first;
           int d = q.front().second;
           m[d].push_back(temp->data);
           q.pop();
           if(temp->left != NULL) q.push({temp->left,d-1});
           if(temp->right != NULL) q.push({temp->right,d+1});
       }
       
       for(auto i : m){
           for(auto j : i.second) ans.push_back(j);
       }
       return ans;
    }
};

