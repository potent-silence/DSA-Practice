class Solution {
    private:
    void dfs(int ind, vector<int> adj[],vector<int>&vis){
        vis[ind]=2;
        
        for(auto node:adj[ind]){  // Traverse all the child nodes of the main node
            if(vis[node]==2)   return;// If the node is visited and is also available in the path then return true
            else if(!vis[node]){
                // If node is not visited then visit it and increment in path
                dfs(node,adj,vis);
                if(vis[node]==2)    return;// This situation occurs when the node has occured a cycle or else vis[node] will be 1
            }
        }
        
        vis[ind]=1;// After returning from the path set the vis[ind]=1 as a type of clearing
    }
    
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int>vis(V,0),ans; // We are here using visited array for 2 purpose 1 for marking the visited array with assigning them 1
                                // and another for marking when are traversing the path by DFS by marking it as 2 and clearing it to 1 again
                                // If the 2 does not get clear in the process then that means we have found a cycle which will also help the other
                                // nodes to mark themselves as part of it.
        
        for(int i=0;i<V;i++)
            if(!vis[i])    dfs(i,adj,vis);
                
        for(int i=0;i<V;i++)
            if(vis[i]==1)   ans.push_back(i);
        
        return ans;
    }
};

/* Approach:
    Anyone who is part of cycle or anyone who is connected to cycle along its one of the path is not a safe node. We will only reset the
    path during returning if we do not find the cycle along the path.
*/
