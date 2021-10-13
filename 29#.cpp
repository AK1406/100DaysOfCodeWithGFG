/*
Given strings A, B, and C, find whether C is formed by an interleaving of A and B.

An interleaving of two strings S and T is a configuration such that it creates a new string Y from the concatenation substrings of A and B and |Y| = |A + B| = |C|

For example:

A = "XYZ"

B = "ABC"

so we can make multiple interleaving string Y like, XYZABC, XAYBCZ, AXBYZC, XYAZBC and many more so here your task is to check whether you can create a string Y which can be equal to C.

Specifically, you just need to create substrings of string A and create substrings B and concatenate them and check whether it is equal to C or not.

Note: a + b is the concatenation of strings a and b.

Return true if C is formed by an interleaving of A and B, else return false.

Example 1:

Input:
A = YX, B = X, C = XXY
Output: 0
Explanation: XXY is not interleaving
of YX and X
Example 2:

Input:
A = XY, B = X, C = XXY
Output: 1
Explanation: XXY is interleaving of
XY and X.

Expected Time Complexity: O(N * M)
Expected Auxiliary Space: O(N * M)
here, N = length of A, and M = length of B
*/

class Solution{
  public:
  unordered_map<string,bool> mem;
   bool helper(string s1,string s2,string s3,int l1,int l2,int l3,int i,int j,int k){
       if(k==l3) return i==l1&&j==l2;
       string temp = to_string(i)+"#"+to_string(j)+"#"+to_string(k);
       if(mem.find(temp)!=mem.end())
          return mem[temp];
       
       if(i==l1&&s2[j]==s3[k]) return mem[temp]=helper(s1,s2,s3,l1,l2,l3,i,j+1,k+1);
       if(j==l2&&s1[i]==s3[k]) return mem[temp]=helper(s1,s2,s3,l1,l2,l3,i+1,j,k+1);
       
       bool one = false,two = false;
       if(s1[i]==s3[k])
           one = helper(s1,s2,s3,l1,l2,l3,i+1,j,k+1);
       if(s2[j]==s3[k])
           two = helper(s1,s2,s3,l1,l2,l3,i,j+1,k+1);
       
       return mem[temp] = one or two;
   }
    /*You are required to complete this method */
    bool isInterleave(string A, string B, string C) 
    {
        //Your code here
    int n1=A.length();
       int n2=B.length();
       int n3=C.length();
       if(n1+n2!=n3) return false;
       
       return helper(A,B,C,n1,n2,n3,0,0,0);       
    }

};
