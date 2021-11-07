/*
Given two integers dividend and divisor. Find the quotient after dividing dividend by divisor without using multiplication, division and mod operator.

Example 1:

Input:
a = 10, b= 3
Output: 3
Exaplanation:
10/3 gives quotient as 3 
and remainder as 1.
Example 2:

Input:
a = 43, b = -8
Output: -5
Explanation:
43/-8 gives quotient as -5 and 
remainder as 3.

Expected Time Complexity: O(log(a))
Expected Auxiliary Space: O(1)
 
*/

class Solution
{
    public:
    long long divide(long long dividend, long long divisor) 
    {
        //code here
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        long dvd = labs(dividend), dvs = labs(divisor), ans = 0;
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        while (dvd >= dvs) {
            long temp = dvs, m = 1;
            while (temp << 1 <= dvd) {
                temp <<= 1;
                m <<= 1;
            }
            dvd -= temp;
            ans += m;
        }
        return sign * ans;
    }
};
