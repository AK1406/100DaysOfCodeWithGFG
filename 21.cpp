vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        // code here
        unordered_map<int,int>n_root;
        vector<pair<int,int>>adj[n+5];
        for(int i=0;i<p;i++){
            n_root[b[i]]=true;
            adj[a[i]].push_back({b[i],d[i]});
        }
        vector<vector<int>>ans;
        for(int i=1;i<=n;i++){
            if(n_root[i]==0&&adj[i].size()){
                int curr = adj[i][0].first;
                 int _min=adj[i][0].second;
                
                while(curr!=i){
            
                     if(adj[curr].size()){
                          _min = min(_min,adj[curr][0].second);
                    curr = adj[curr][0].first;
                        
                         
                     }else break;
                }
                if(curr!=i){
                    ans.push_back({i,curr,_min});
                }
            }
        }
        return ans;
        
    }
