/*
Sort an array of 0s, 1s and 2s

Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.
Input: 
N = 5
arr[]= {0 2 1 2 0}
Output:
0 0 1 2 2
Explanation:
0s 1s and 2s are segregated 
into ascending order.
*/




class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // coode here 
        int i=0,count0=0,count1=0,count2=0;
        for(;i<n;i++){
            if(a[i]==0)
                count0++;
            else if(a[i]==1)
                count1++;
            else
                count2++;
        }
        //put 0
        for(int j=0;j<count0;j++){
            a[j]=0;
        }
        
        //put 1
        for(int j=count0;j<(count0+count1);j++){
            a[j]=1;
        }
        
        //put 2
        for(int j=count0+count1;j<n;j++){
            a[j]=2;
        }
        
    }
    
};
