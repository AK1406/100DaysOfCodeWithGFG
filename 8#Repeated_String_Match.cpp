/*
Repeated String Match

Given two strings A and B, find the minimum number of times A has to be repeated such that B becomes a substring of the repeated A. If B cannot be a substring of A no matter how many times it is repeated, return -1.

Example 1:

Input: A = "abcd", B = "cdabcdab"
Output: 3
Explanation: After repeating A three times, 
we get "abcdabcdabcd".

Example 2:

Input: A = "aa", B = "a"
Output: 1
Explanation: B is already a substring of A

Expected Time Complexity: O(|A| * |B|)
Expected Auxiliary Space: O(1)
*/

//Brute force appraoch

int repeatedStringMatch(string A, string B) 
    {
        // Your code goes here
        int count =1;
        while(!(A.find(B) != string::npos)){
            count++;
        }
        return count;
    }

//optimized

    int repeatedStringMatch(string A, string B) 
    {
        // Your code goes here
    int count = 1;
    string S = A;
    while(S.size() < B.size())
    {
        S += A;
        count++;
    }
     
    if (S.find(B)  != string::npos){
    return count;
    }
     S = S+A;
    if ((S.find(B)  != string::npos)){
        return count + 1;
    }
           
    return -1;
    }
