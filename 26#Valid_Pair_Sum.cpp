/*
Valid Pair Sum
Given an array of size N, find the number of distinct pairs {i, j} (i != j) in the array such that the sum of a[i] and a[j] is greater than 0.

Example 1:

Input: N = 3, a[] = {3, -2, 1}
Output: 2
Explanation: {3, -2}, {3, 1} are two 
possible pairs.
Example 2:

Input: N = 4, a[] = {-1, -1, -1, 0}
Output: 0
Explanation: There are no possible pairs.

Expected Time Complexity: O(N * Log(N))
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 105 
-104  ≤ a[i] ≤ 104
*/

class Solution{
    
    public:
    long long ValidPair(int a[], int n) 
    { 
    	// Your code goes here 
        long long ans =0;
        sort(a,a+n);
        int j=0;
        for(int i=0;i<n;i++){
            if(a[i] <= 0){
                continue;
            }else{
                j =lower_bound(a, a + n, -a[i] + 1) - a;
            }
            ans += i-j;
        }
        return ans;
    }   
};
