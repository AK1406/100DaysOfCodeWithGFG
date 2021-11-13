/*
Given a string S consisting of only opening and closing curly brackets '{' and '}', find out the minimum number of reversals required to convert the string into a balanced expression.
A reversal means changing '{' to '}' or vice-versa.

Example 1:

Input:
S = "}{{}}{{{"
Output: 3
Explanation: One way to balance is:
"{{{}}{}}". There is no balanced sequence
that can be formed in lesser reversals.
â€‹Example 2:

Input: 
S = "{{}{{{}{{}}{{"
Output: -1
Explanation: There's no way we can balance
this sequence of braces.

Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(1).

*/
int countRev (string s)
{
    // your code here
    int n=s.size();
   if(n%2!=0)
       return -1;
   int o=0,c=0;
   int ans=0;
   for(int i=0;i<n;i++)
   {
       if(s[i]=='}' && c>=o)
           {
               o++;
               ans++;
           }
       else
       if(s[i]=='{')
               o++;
       else
           c++;
   }
   int temp=abs(o-c);
   return ans+(temp)/2;

}
