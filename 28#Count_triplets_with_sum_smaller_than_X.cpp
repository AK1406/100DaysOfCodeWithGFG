/*
Count triplets with sum smaller than X.

Given an array arr[] of distinct integers of size N and a value sum, the task is to find the count of triplets (i, j, k), 
having (i<j<k) with the sum of (arr[i] + arr[j] + arr[k]) smaller than the given value sum.

Example 1:

Input: N = 4, sum = 2
arr[] = {-2, 0, 1, 3}
Output:  2
Explanation: Below are triplets with 
sum less than 2 (-2, 0, 1) and (-2, 0, 3). 
 
Example 2:

Input: N = 5, sum = 12
arr[] = {5, 1, 3, 4, 7}
Output: 4
Explanation: Below are triplets with 
sum less than 12 (1, 3, 4), (1, 3, 5), 
(1, 3, 7) and (1, 4, 5).

Expected Time Complexity: O(N2).
Expected Auxiliary Space: O(1).


*/

class Solution{	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    sort(arr,arr+n);
	    int count =0;
	    for(int i=0;i<n-2;i++){
	        int j=i+1,k=n-1;
	        while(j<k){
	            if(arr[i]+arr[j]+arr[k] >= sum){
	                k--;
	            }else{
	                count += k-j;
	                j++;
	            }
	            
	        }
	    }
	    return count;
	}
		
};

