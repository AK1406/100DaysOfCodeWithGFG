/*
Check Tree Traversal

Given Preorder, Inorder and Postorder traversals of some tree of size N. The task is to check if they are all of the same tree or not.

Example 1:

Input:
N = 5
preorder[] = {1, 2, 4, 5, 3}
inorder[] = {4, 2, 5, 1, 3}
postorder[] = {4, 5, 2, 3, 1}
Output: Yes
Explanation: 
All of the above three traversals 
are of the same tree.
           1
         /   \
        2     3
      /   \
     4     5
Example 2:

Input:
N = 5
preorder[] = {1, 5, 4, 2, 3}
inorder[] = {4, 2, 5, 1, 3}
postorder[] = {4, 1, 2, 3, 5}
Output: No
Explanation: The three traversals can 
not be of the same tree.

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N)

*/

class Solution{
    public:
    bool checktree(int preorder[], int inorder[], int postorder[], int N) 
    { 
    	// Your code goes here
    	if (N == 0){
        return 1;
    	}
 
    if (N == 1){
        return (preorder[0] == inorder[0]) && (inorder[0] == postorder[0]);
    }
 
    int index = -1, flag = 0;
    for (int i = 0; i < N; ++i)
        if (inorder[i] == preorder[0]) {
            index = i;
            break;
        }
   
    if(index != -1){
      for(int i = 0; i < N; i++)
        if(preorder[0] == postorder[i]){
            flag = 1; break;
            
        }
    }
 
    if (index == -1 || flag == 0){
        return 0;
    }
 
    int ret1 = checktree(preorder + 1, inorder, postorder, index);
 
    int ret2 = checktree(preorder + index + 1, inorder + index + 1,postorder + index, N - index - 1);
 
    return (ret1 && ret2);
    } 

};
