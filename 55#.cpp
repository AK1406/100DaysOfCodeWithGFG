/*
Given two strings a and b consisting of lowercase characters. The task is to check whether two given strings are an anagram of each other or not. An anagram of a string is another string that contains the same characters, only the order of characters can be different. For example, “act” and “tac” are an anagram of each other.

Example 1:

Input:
a = geeksforgeeks, b = forgeeksgeeks
Output: YES
Explanation: Both the string have same
characters with same frequency. So, 
both are anagrams.
Example 2:

Input:
a = allergy, b = allergic
Output: NO
Explanation:Characters in both the strings
are not same, so they are not anagrams.

Expected Time Complexity: O(|a|+|b|).
Expected Auxiliary Space: O(Number of distinct characters).

*/

class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
        // Your code here
     bool ans = true;
     int len=1;
     sort(a.begin(),a.end());
     sort(b.begin(),b.end());
     if(a.size() < b.size()){
         len = b.size();
     }
     else{
         len =a.size();
     }
    for(int i=0;i<len;i++){

        if(a[i]!=b[i]){
            ans = false;
            break;
        }
    }
    return ans;
        
    }

};
