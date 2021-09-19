/*
Median of 2 Sorted Arrays of Different Sizes 

Given two sorted arrays array1 and array2 of size m and n respectively. Find the median of the two sorted arrays.

Example 1:

Input:
m = 3, n = 4
array1[] = {1,5,9}
array2[] = {2,3,6,7}
Output: 5
Explanation: The middle element for
{1,2,3,5,6,7,9} is 5

Example 2:

Input:
m = 2, n = 4
array1[] = {4,6}
array2[] = {1,2,3,5}
Output: 3.5

Expected Time Complexity: O(min(log n, log m)).
Expected Auxiliary Space: O((n+m)/2).


*/


class Solution{
    public:
    double mid(vector<int>& array1, vector<int>& array2,double key){
        int i=0,j=0,k=0;
        int ans =0;
        while(i < array1.size() && j < array2.size()){
            
            if(array1[i] < array2[j]){
                k++;
                if(k == key){
                    ans= array1[i];
                    break;
                }
                i++;
            }else{
                k++;
                if(k==key){
                    ans= array2[j];
                        break;
                }
                j++;
            }
        }
        while(i<array1.size()){
            k++;
                if(k == key){
                    ans= array1[i];
                        break;
                }
                i++;
        }
        while(j < array2.size()){
            k++;
            if(k == key){
                ans= array2[j];
                    break;
            }
        j++;
        }
        return ans;
    }
    
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here
        int s = array1.size() + array2.size();
        int key=0;
        double res=0;
        if(s%2==0){
            key = s/2;
            res = (mid(array1,array2,key) + mid(array1,array2,key+1))/2;
        
        }else{
            key = s/2 +1;
            res = mid(array1,array2,key);
        }
    return res;
    }
};
