/*
Count Occurences of anagrams

Given a word pat and a text txt. Return the count of the occurences of anagrams of the word in the text.

Example 1:

Input:
txt = forxxorfxdofr
pat = for
Output: 3
Explanation: for, orf and ofr appears
in the txt, hence answer is 3.
Example 2:

Input:
txt = aabaabaa
pat = aaba
Output: 4
Explanation: aaba is present 4 times
in txt.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(26) or O(256)

*/

class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    vector<int> v(26,0);
	    vector<int> v1(26,0);
	    int k=1,count=0;
	    
	    for(int i=0;i<pat.size();i++){
	        v[pat[i]-'a']++;
	    }
	    
	    for(int i=0;i<pat.size();i++){
	        v1[txt[i]-'a']++;
	    }
	    if(v==v1){
	        count++;
	    }
	    v1[txt[0]-'a']--;
	    for(int i=pat.size();i<txt.size();i++){
	        v1[txt[i]-'a']++;
	        if(v==v1){
	            count++;
	        }
	        v1[txt[k]-'a']--;
	        k++;
	    }
	    return count;
	}

};
