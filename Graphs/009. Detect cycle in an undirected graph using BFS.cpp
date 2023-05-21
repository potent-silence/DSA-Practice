class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(vis[i])  continue;
            queue<pair<int,int>>ind;
            ind.push({i,-1});
            while(!ind.empty()){
                pair<int,int> f=ind.front();
                ind.pop();
                vis[f.first]=1;
                for(auto it:adj[f.first]){
                    if(!vis[it])    ind.push({it,f.first});
                    else if(it!=f.second)   return true;
                }
            }
        }
        return false;
    }
};
