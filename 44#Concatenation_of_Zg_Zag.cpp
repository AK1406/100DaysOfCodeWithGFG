/*
Concatenation od Zig-Zag

Given a string and number of rows ‘n’. Print the string formed by concatenating n rows when the input string is written in row-wise Zig-Zag fashion.

Example 1:

Input: 
str = "ABCDEFGH"
n = 2
Output: "ACEGBDFH"
Explanation: 
Let us write input string in 
Zig-Zag fashion in 2 rows.
A   C   E   G  
  B   D   F   H
Now concatenate the two rows and ignore 
spaces in every row. We get "ACEGBDFH"
Example 2:

Input: 
str = "GEEKSFORGEEKS"
n = 3
Output: GSGSEKFREKEOE
Explanation: 
Let us write input string in 
Zig-Zag fashion in 3 rows.
G       S       G       S
  E   K   F   R   E   K
    E       O       E
Now concatenate the two rows and ignore spaces
in every row. We get "GSGSEKFREKEOE"

Expected Time Complexity: O(|str|).
Expected Auxiliary Space: O(|str|).

Constraints:
1 ≤ N ≤ 105
*/
class Solution{
    public:
    string convert(string s, int n) {
        //code
        if(n==1){
            return s;
        }
        string ans ="";
        string row_string[n]={""};
        string controller;
        
        int row =0;
        for(int i=0;i<s.size();i++){
            row_string[row].push_back(s[i]);
            if(row == n-1){
                controller ="up";
            }
            if(row ==0){
                controller ="down";
            }
            controller == "up" ? row-- : row++;
        }
        for(int i =0;i<n;i++){
            ans += row_string[i];
        }
        return ans;
    }
};
