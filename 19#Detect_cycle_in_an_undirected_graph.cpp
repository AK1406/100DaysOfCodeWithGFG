/*
Detect cycle in an undirected graph.

Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. 

Example 1:

Input:   

Output: 1
Explanation: 1->2->3->4->1 is a cycle.
Example 2:

Input: 

Output: 0
Explanation: No cycle in the graph.
 

Expected Time Complexity: O(V + E)
Expected Space Complexity: O(V)

Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1#

*/

class Solution {
  public:
  vector<bool> vis;
   bool ans;
   void dfs(vector<int> adj[], int v, int p) {
    vis[v] = true;
    for (auto x : adj[v]) {
        if (x == p)continue;
        if (vis[x]) {
            ans = true;
            return;
        }
        else dfs(adj, x, v);
    }
}
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
    vis.assign(V + 1, false);
    ans = false;
    for (int i = 0; i < V; i++){
        if (!vis[i]){
        dfs(adj, i, -1);
        }
    }
    return ans;

    }
};
