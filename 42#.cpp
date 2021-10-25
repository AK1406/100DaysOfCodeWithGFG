/*
An IT company is working on a large project. The project is broken into N modules and distributed to different teams. Each team can work parallelly. The amount of time (in months) required to complete each module is given in an array duration[ ] i.e. time needed to complete ith module is duration[i] months. 
You are also given M dependencies such that for each i (1 ≤ i ≤ M)  dependencies[i][1]th module can be started after dependencies[i][0]th module is completed.
As the project manager, compute the minimum time required to complete the project.
Note: It is guaranteed that a module is not dependent on itself.

Example 1:

Input:
N = 6, M = 6
duration[] = {1, 2, 3, 1, 3, 2}
dependencies[][]:
[[5, 2]
 [5, 0]
 [4, 0] 
 [4, 1]
 [2, 3]
 [3, 1]]
Output: 
8
Explanation:The Graph of dependency forms this and 
the project will be completed when Module 
1 is completed which takes 8 months.

Example 2:

Input:
N = 3, M = 3
duration[] = {5, 5, 5}
dependencies[][]:
[[0, 1]
 [1, 2]
 [2, 0]]
Output: 
-1
Explanation: 
There is a cycle in the dependency graph 
hence the project cannot be completed.

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(N)

*/


class Solution{
    public:
    int minTime(vector<pair<int, int>> &dependency, int duration[], int n, int m) {
        // 	Write your code here
        vector<int> adj[n],in(n),dist(n,INT_MIN);
        vector<bool> vis(n,false),rec(n,false);
        for(auto& edge:dependency){
            adj[edge.first].push_back(edge.second);
            in[edge.second]++;
        }
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(!in[i]){
                dist[i] = duration[i];
                q.push(i);
            }
        }
        int cnt = 0;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            
            cnt++;
            
            for(auto& u:adj[v]){
                in[u]--;
                dist[u] = max(dist[u],dist[v]);
                if(!in[u]){
                    dist[u] += duration[u];
                    q.push(u);
                }
            }
        }
        return (cnt==n)?*max_element(dist.begin(),dist.end()):-1;
    }
};
