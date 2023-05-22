class Solution {
public:
    bool dfs(int ind, vector<int> adj[],vector<int>&vis){
        for(auto node:adj[ind]){  // Traverse all the child nodes of the main node
            if(vis[node]==0){
                // If the node is not colored then color it with opposite color and move towards it
                vis[node]=-vis[ind];
                if(!dfs(node,adj,vis))  return false;// If we get a false result then only return don't return for true from here
            }
            else if(vis[node]==vis[ind])   return false;// If node is colored and same as parent node then return false
        }
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int>vis(V,0);
	    for(int i=0;i<V;i++){
	        if(vis[i]!=0)  continue;
	        vis[i]=1;
	        if(!dfs(i,adj,vis)) return false;// If we get a false result then only return don't return for true from here
	    }
	    
	    return true;// Return true result from here only
	}
};
