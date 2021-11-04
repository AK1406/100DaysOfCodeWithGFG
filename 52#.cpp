/*
Given an array A of N integers. You have to find whether a combination of four elements in the array whose sum is equal to a given value X exists or not.
 

Example 1:

Input:
N = 6
A[] = {1, 5, 1, 0, 6, 0}
X = 7
Output:
1

Explantion:
1, 5, 1, 0 are the four elements which makes sum 7.
 

Expected Time Complexity: O(N3)
Expected Auxiliary Space: O(1)


*/
bool find4Numbers(int A[], int n, int X)  
{
    sort(A,A+n);
    bool ans=0;
    for(int i=0;i<n-3;i++){
        for(int j=i+1;j<n-2;j++){
            int st=j+1;
            int end=n-1;
            while(st<end){
                int sum=A[i]+A[j]+A[st]+A[end];
                if(sum>X){
                    end--;
                }else if(sum<X){
                    st++;
                }else if(sum==X){
                    return true;
                    ans=1;
                }
            }
            if(ans==1){
                break;
            }
        }
    }
    return false;
}
