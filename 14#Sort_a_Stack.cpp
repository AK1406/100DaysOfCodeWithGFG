/*
Sort a Stack.

Given a stack, the task is to sort it such that the top of the stack has the greatest element.

Example 1:

Input:
Stack: 3 2 1
Output: 3 2 1
Example 2:

Input:
Stack: 11 2 32 3 41
Output: 41 32 11 3 2

Expected Time Complexity: O(N*N)
Expected Auxilliary Space: O(N) recursive.
*/




/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
   //Your code here
   stack<int>tempStack;
   int temp=0;
   while(!s.empty()){
       temp = s.top();
       s.pop();
       while(!tempStack.empty() && tempStack.top() < temp){
           s.push(tempStack.top());
           tempStack.pop();
       }
       tempStack.push(temp);
   }
   while(!s.empty()){
       s.pop();
   }
   
   while(!tempStack.empty()){
       s.push(tempStack.top());
       tempStack.pop();
   }
}
