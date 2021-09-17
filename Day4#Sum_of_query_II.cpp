/*You are given an array arr[] of n integers and q queries in an array queries[] of length 2*q containing l, r pair for all q queries. 
You need to compute the following sum over q queries.

Array is 1-Indexed.

Example 1:

Input: n = 4
arr = {1, 2, 3, 4}
q = 2
queries = {1, 4, 2, 3}
Output: 10 5
Explaination: In the first query we need sum 
from 1 to 4 which is 1+2+3+4 = 10. In the 
second query we need sum from 2 to 3 which is 
2 + 3 = 5.

Expected Time Complexity: O(n+q)
Expected Auxiliary Space: O(n)

*/

class Solution{
public:
    vector<int> querySum(int n, int arr[], int q, int queries[])
    {
        // code here
        int s=0,e=0,sum=0;
         vector<int> arrSum;
        for(int i=0;i<2*q;i +=2){
            s=queries[i];
            e=queries[i+1];
            for(int j=s;j<=e;j++){
                sum +=arr[j];
            }
            arrSum.push_back(sum);
            sum=0;
        }
        return arrSum;
    }
};
