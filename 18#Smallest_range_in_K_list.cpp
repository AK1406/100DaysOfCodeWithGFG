/*
Smallest Range in K List

Given K sorted lists of integers, KSortedArray[] of size N each. The task is to find the smallest range that includes at least one element from each of the K lists. If more than one such range's are found, return the first such range found.

Example 1:

Input:
N = 5, K = 3
KSortedArray[][] = {{1 3 5 7 9},
                    {0 2 4 6 8},
                    {2 3 5 7 11}}
Output: 1 2
Explanation: K = 3
A:[1 3 5 7 9]
B:[0 2 4 6 8]
C:[2 3 5 7 11]
Smallest range is formed by number 1
present in first list and 2 is present
in both 2nd and 3rd list.
Example 2:

Input:
N = 4, K = 3
KSortedArray[][] = {{1 2 3 4},
                    {5 6 7 8},
                    {9 10 11 12}}
Output: 4 9
Your Task :

Expected Time Complexity : O(n * k *log k)
Expected Auxilliary Space  : O(k)

*/

class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
          //code here
      set<pair<int, pair<int, int>>> s;
       pair<int, int> res{0, INT_MAX};
       
       for(size_t i = 0; i < k; ++i){
           s.insert( {KSortedArray[i][0], {i, 0}} );
       }
       
       while( !s.empty() ){
           // Get the min and max elements from ordered set now
           int minVal = s.begin()->first; 
           int maxVal = s.rbegin()->first;
           if( res.second - res.first > maxVal - minVal )
           {
               res.first = minVal;
               res.second = maxVal;
           }
           
           // Now we remove the minimum element from k-element ordered set
           int r = s.begin()->second.first;
           int c = s.begin()->second.second;
           s.erase(s.begin());
           if( c + 1 == n )
               break;
           s.insert( {KSortedArray[r][c+1], {r, c+1}} );
       }
       return res;
    }
};
