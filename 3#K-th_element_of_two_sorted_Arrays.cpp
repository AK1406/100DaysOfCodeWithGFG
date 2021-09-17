/*

K-th element of two sorted Arrays

Given two sorted arrays arr1 and arr2 of size N and M respectively and an element K. The task is to find the element that would be 
at the k’th position of the final sorted array.
 
Input:
arr1[] = {2, 3, 6, 7, 9}
arr2[] = {1, 4, 8, 10}
k = 5
Output:
6

Explanation:
The final sorted array would be -
1, 2, 3, 4, 6, 7, 8, 9, 10
The 5th element of this array is 6.

Expected Time Complexity: O(Log(N) + Log(M))
Expected Auxiliary Space: O(Log (N))

*/



class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int i=0,j=0,key=0;
        
        while(i<n && j<m){
            if(arr1[i]<arr2[j]){
                key++;
                if(key == k){
                    return arr1[i];
                }
                i++;
            }else{
                key++;
                if(key == k){
                    return arr2[j];
                }
                j++;
            }
        }
        
        while(i < n){
             key++;
                if(key == k){
                    return arr1[i];
                }
                i++;
        }
        while(j < m){
             key++;
                if(key == k){
                    return arr2[j];
                }
                j++;
        }
    }
};
