/*
Maximum difference of zeros and ones in binary string.

Given a binary string S consisting of 0s and 1s. The task is to find the maximum difference of the number of 0s and the number of 1s (number of 0s – number of 1s) in the substrings of a string.

Note: In the case of all 1s, the answer will be -1.

Example 1:

Input : S = "11000010001" 
Output : 6 
Explanatio: From index 2 to index 9, 
there are 7 0s and 1 1s, so number 
of 0s - number of 1s is 6. 
Example 2:

Input: S = "111111"
Output: -1
Explanation: S contains 1s only 

Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(|S|)

*/
class Solution{
public:	
	int maxSubstring(string S)
	{
	    // Your code goes here
	    int ans = INT_MIN;
	    int res =0;
	    for(char x: S){
	        if(x == '1'){
	            res--;
	        }else{
	            res++;
	        }
	        ans = max(ans,res);
	        if(res < 0){
	            res =0;
	        }
	    }
	    
	return ans;
	}
};


