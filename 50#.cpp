/*

Given an integer array. The task is to find the maximum of the minimum of every window size in the array.
Note: Window size varies from 1 to the size of the Array.

Example 1:

Input:
N = 7
arr[] = {10,20,30,50,10,70,30}
Output: 70 30 20 10 10 10 10 
Explanation: 
1.First element in output
indicates maximum of minimums of all
windows of size 1.
2.Minimums of windows of size 1 are {10},
 {20}, {30}, {50},{10}, {70} and {30}. 
 Maximum of these minimums is 70. 
3. Second element in output indicates
maximum of minimums of all windows of
size 2. 
4. Minimums of windows of size 2
are {10}, {20}, {30}, {10}, {10}, and
{30}.
5. Maximum of these minimums is 30 
Third element in output indicates
maximum of minimums of all windows of
size 3. 
6. Minimums of windows of size 3
are {10}, {20}, {10}, {10} and {10}.
7.Maximum of these minimums is 20. 
Similarly other elements of output are
computed.
Example 2:

Input:
N = 3
arr[] = {10,20,30}
Output: 30 20 10
Explanation: First element in output
indicates maximum of minimums of all
windows of size 1.Minimums of windows
of size 1 are {10} , {20} , {30}.
Maximum of these minimums are 30 and
similarly other outputs can be computed

Expected Time Complxity : O(N)
Expected Auxilliary Space : O(N)
*/


class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        // Your code here
        stack<int> s;
    vector<int> ans(n, 0), l(n + 1, 0);
    for (int i = 0; i < n; i++) { // Nearest smaller element to left.
        while (!s.empty() && arr[s.top()] >= arr[i])s.pop();
        if (s.empty())l[i] = i + 1;
        else l[i] = i - s.top();
        s.push(i);
    }
    while (!s.empty())s.pop();
    for (int i = n - 1; i >= 0; i--) { // Nearest smaller element to right.
        while (!s.empty() && arr[s.top()] >= arr[i])s.pop();
        if (s.empty())l[i] += n - 1 - i;
        else l[i] += s.top() - i - 1;
        s.push(i);
        ans[l[i] - 1] = max(ans[l[i] - 1], arr[i]);
    }
    for (int i = n - 2; i >= 0; i--)ans[i] = max(ans[i + 1], ans[i]);
    return ans;
    }
};
