/* Maximum Rectangular Area 

Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. 
For simplicity, assume that all bars have the same width and the width is 1 unit, there will be N bars height of each bar will be given by the array arr.

Example 1:

Input:
N = 7
arr[] = {6,2,5,4,5,1,6}
Output: 12

Example 2:

Input:
N = 8
arr[] = {7 2 8 9 1 3 6 5}
Output: 16
Explanation: Maximum size of the histogram 
will be 8  and there will be 2 consecutive 
histogram. And hence the area of the 
histogram will be 8x2 = 16.

Expected Time Complxity : O(N)
Expected Auxilliary Space : O(N)


*/

class Solution
{
    public:
    vector<long long> leftSmaller(long long arr[], int n){
        stack<long long> s;
        vector<long long> res(n);
        for(long long i=0; i<n; i++){
            while(!s.empty() && arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(s.empty()){
                res[i] = -1;
            } else {
                res[i] = s.top();
            }
            s.push(i);
        }
        return res;
    }
    vector<long long> rightSmaller(long long arr[], int n){
        stack<long long> s;
        vector<long long> res(n);
        for(long long i=n-1; i>=0; i--){
            while(!s.empty() && arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(s.empty()){
                res[i] = n;
            } else {
                res[i] = s.top();
            }
            s.push(i);
        }
        return res;
    }
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        long long ans = 0;
        vector<long long> left = leftSmaller(arr, n);
        vector<long long> right = rightSmaller(arr, n);
        for(long long i=0; i<n; i++){
            long long mx = (right[i]-left[i]-1)*arr[i];
            ans = max(ans, mx);
        }
        return ans;
    }
};
