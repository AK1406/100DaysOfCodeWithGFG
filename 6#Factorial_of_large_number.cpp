/*
Factorail of a large number

Given an integer N, find its factorial.

Example 1:

Input: N = 5
Output: 120
Explanation : 5! = 1*2*3*4*5 = 120
Example 2:

Input: N = 10
Output: 3628800
Explanation :
10! = 1*2*3*4*5*6*7*8*9*10 = 3628800

Expected Time Complexity : O(N2)
Expected Auxilliary Space : O(1)

*/

class Solution {
public:
    vector<int> factorial(int N){
        // code here
        vector<int>fact;
        fact.push_back(1);
        int i,j,carry=0;
        for(i=2;i<=N;i++){
            carry =0;
            for(j=0;j<fact.size();j++){
                int data = fact[j]*i + carry;
                fact[j] = data%10;
                carry = data/10;
            }
            while(carry){
                fact.push_back(carry%10);
                carry = carry/10;
            }
        }
        reverse(fact.begin(),fact.end());
        return fact;
    }
};
