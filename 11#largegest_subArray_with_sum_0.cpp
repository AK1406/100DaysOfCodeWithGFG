/*
Largest SubArray with sum 0.

Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Example 1:

Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).


*/


class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int,int>mp;
        int sum=0,len=0;
        for(int i=0;i<n;i++){
            sum += A[i];
            if(sum == 0){
                len = max(len,i+1);
            }
            if(mp.find(sum) == mp.end()){
                mp[sum] =i;
            }else{
                len = max(len,i-mp[sum]);
            }
        }
        return len;
    }
};
