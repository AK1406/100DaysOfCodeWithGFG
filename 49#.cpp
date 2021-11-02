/*
A prime number is a Circular Prime Number if all of its possible rotations are itself prime numbers. Now given a number N check if it is Circular Prime or Not.
 

Example 1:

Input: N = 197
Output: 1
Explanation: 197 is a Circular Prime because
all rotations of 197 are 197, 719, 971 all of 
the 3 are prime number's hence 197 is a 
circular prime.
Example 2:

Input: N = 101
Output: 0
Explanation: 101 and 11 is prime but 110 is
not a prime number.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function isCircularPrime() which takes N as input parameter and returns 1 if it is Circular Prime otherwise returns 0.
 

Expected Time Complexity: O(Nlog(log(N))
Expected Space Complexity: O(N)

*/




int isCircularPrime(int n) {
	    // Code here
	    string d=to_string(n);
	    for(int i=0;i<d.size();i++){
	        int num=0,j=i;
	        while(j<d.size())num*=10,num+=d[j]-'0',j++;
	        j=0;
	        while(j<i)num*=10,num+=d[j]-'0',j++;
	        if(num==1)return 0;
	        for(int x=2;x*x<=num;x++)if(num%x==0)return 0;
	    }
	    return 1;
	}

// O(logN * LogN * sqrt(N))
