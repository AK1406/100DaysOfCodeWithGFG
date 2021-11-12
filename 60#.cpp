/*
Given a directed graph and two vertices ‘u’ and ‘v’ in it. Find the number of possible walks from ‘u’ to ‘v’ with exactly k edges on the walk modulo 109+7.
 

Example 1:

Input 1: graph = {{0,1,1,1},{0,0,0,1}, 
{0,0,0,1}, {0,0,0,0}}, u = 0, v = 3, k = 2
Output: 2
Explanation: Let source ‘u’ be vertex 0, 
destination ‘v’ be 3 and k be 2. The output 
should be 2 as there are two walk from 0 to 
3 with exactly 2 edges. The walks are {0, 2, 3}
and {0, 1, 3}.

Your Task:
You don't need to read or print anything. Your task is to complete the function MinimumWalk() which takes graph, u, v and k as input parameter and returns total possible paths from u to v using exactly k edges modulo 109+7.
Note: In graph, if graph[i][j] = 1, it means there is an directed edge from vertex i to j.
 

Expected Time Complexity: O(n3)
Expected Space Complexity: O(n3)

*/

class Solution {
  public:
	int MinimumWalk(vector<vector<int>>&graph, int u, int v, int k){
	    // Code here
	    int n = graph.size(), mod = 1e9 + 7;
    vector<vector<int64_t>> dp(n + 1, vector<int64_t>(k + 1, 0));
    dp[u][0] = 1; // base case.
    for (int j = 1; j <= k; j++) {
        for (int i = 0; i < n; i++) {
            for (int p=0; p<n; p++)if(graph[p][i])(dp[i][j] += dp[p][j - 1])%=mod;
        }
    }
    return dp[v][k];
	}

};
