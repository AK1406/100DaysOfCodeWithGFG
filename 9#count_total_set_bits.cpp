/*
Count total set bits

You are given a number N. Find the total count of set bits for all numbers from 1 to N(both inclusive).

Example 1:

Input: N = 4
Output: 5
Explanation:
For numbers from 1 to 4.
For 1: 0 0 1 = 1 set bits
For 2: 0 1 0 = 1 set bits
For 3: 0 1 1 = 2 set bits
For 4: 1 0 0 = 1 set bits
Therefore, the total set bits is 5.

Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1).

*/

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        // Your logic here
        int result=0,total=0;
        int x=1;
        while(x <= n){
            x *= 2;
            int a = ((n+1)/x);
            int rem = (n+1)%x;
            total = a * (x/2);
            if(rem > (x/2)){
                total += rem-(x/2);
            }
            result += total;
        }
        return result;
    }
};
