class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(pair<int,int> ind, vector<int> adj[],vector<int>&vis){
        vis[ind.first]=1;// When you visit for the first time mark it as visited
        for(int i=0;i<adj[ind.first].size();i++){  // Traverse all the child nodes of the main node
            if(!vis[adj[ind.first][i]]){     
                // If we get a cycle then only return true
                if(dfs({adj[ind.first][i],ind.first},adj,vis))  return true;
            }
            else if(adj[ind.first][i]!=ind.second) return true;    
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(vis[i])  continue;
            if(dfs({i,-1},adj,vis)) return true;// Recursive Approach
        }
        return false;
    }
};
