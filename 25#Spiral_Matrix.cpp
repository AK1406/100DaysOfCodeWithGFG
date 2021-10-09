/*
Given a matrix of size N x M. You have to find the Kth element which will obtain while traversing the matrix spirally starting from the top-left 
corner of the matrix.

Example 1:

Input: 
N = 3, M = 3, K = 4
A[] = {{1, 2, 3}, 
       {4, 5, 6}, 
       {7, 8, 9}}
Output: 
6
Explanation: Spiral traversal of matrix: 
{1, 2, 3, 6, 9, 8, 7, 4, 5}. Fourth element
is 6.
Example 2:

Input: 
N = 2, M = 2, K = 2 
A[] = {{1, 2},
       {3, 4}} 
Output: 
2
Explanation: Spiral traversal of matrix: 
{1, 2, 4, 3}. Second element is 2.

Expected Time Complexity: O(N*M)
Expected Auxiliary Space: O(1)

*/

class Solution{

	public:
	int findK(vector<vector<int>> &a, int n, int m, int k)
    {
        // Your code goes here
        vector<int>ele;
        int row_start =0,row_end = n-1, col_start = 0, col_end = m-1;
        
        while(row_start <= row_end && col_start <= col_end){
            
            for(int i = col_start;i<=col_end;i++){
                ele.push_back(a[row_start][i]);
               
            }
            row_start++;
            for(int i=row_start;i<=row_end;i++){
                ele.push_back(a[i][col_end]);
                
            }
            col_end--;
            for(int i = col_end;i>=col_start;i--){
                ele.push_back(a[row_end][i]);
            }
            row_end--;
            for(int i = row_end;i>=row_start;i--){
                ele.push_back(a[i][col_start]);
            }
            col_start++;
        }
        
        return ele[k-1];
    }

};
