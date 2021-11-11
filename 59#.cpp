/*
count the number of subarrays

Given an array A[] of N integers and a range(L, R). The task is to find the number of subarrays having sum in the range L to R (inclusive).

Example 1:

Input:
N = 3, L = 3, R = 8
A[] = {1, 4, 6}
Output: 
3
Explanation: 
The subarrays are [1,4], [4] and [6]
Example 2:

Input:
N = 4, L = 4, R = 13
A[] = {2, 3, 5, 8}
Output: 
6
Explanation: 
The subarrays are [2,3], [2,3,5], 
[3,5],[5], [5,8] and [8]

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

*/

class Solution {
  public:
  long long countLessThan(vector<int> arr, long long lim) {
        long long ans = 0;
        for(long long i=0, j=0, cur=0; j<arr.size(); j++) {
            cur += arr[j];
            while(cur > lim) cur -= arr[i++];
            ans += j-i;
        }
        return ans;
    }
    
    long long countSubarray(int N,vector<int> A,long long L,long long R) {
        // code here
        return countLessThan(A, R) - countLessThan(A,L-1);
    }
};

