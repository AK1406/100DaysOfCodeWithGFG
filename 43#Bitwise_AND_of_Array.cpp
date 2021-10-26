/* Bitwise AND of the array

Given an array A[ ] of N integers and an integer X. In one operation, you can change the ith element of the array to any integer value where 1 ≤ i ≤ N. Calculate minimum number of such operations required such that the bitwise AND of all the elements of the array is strictly greater than X.

Example 1:

Input:
N = 4, X = 2
A[] = {3, 1, 2, 7}
Output: 
2
Explanation: 
After performing two operations:
Modified array: {3, 3, 11, 7} 
Now, Bitwise AND of all the elements
is 3 & 3 & 11 & 7 = 3 
Example 2:

Input:
N = 3, X = 1
A[] = {2, 2, 2}
Output: 
0
Your Task:
You don't need to read input or print anything. Your task is to complete the function count( ) which takes N, A[ ] and X as input parameters and returns the minimum number of operations required.

Expected Time Complexity: O(N * Log(max(A[ ])))
Expected Auxiliary Space: O(1)
*/


class Solution{
    public:
    int count(int N, vector<int> A,int X)
    {
        // code here
    int msb = __lg(X), ans = N, temp = 0, vis[N] = {0};
	for (int i = 30; i >= 0; i--) {
		int cnt = 0;
		for (int j = 0; j < N; j++) {
			if (!vis[j] && ((X >> i) & 1) && !((A[j] >> i) & 1) ){
			    temp++;
			    vis[j] = 1;}
			if (!((A[j] >> i) & 1) && !vis[j])
			{
			    cnt++;
			}
		}
		if (!((X >> i) & 1))ans = min(ans, temp + cnt);
	}
	return ans;
    }
};
