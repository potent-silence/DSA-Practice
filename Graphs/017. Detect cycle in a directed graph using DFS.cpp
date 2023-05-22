class Solution {
  private:
    bool dfs(int ind, vector<int> adj[],vector<int>&vis,vector<int> &path){
        vis[ind]=1;
        
        for(auto node:adj[ind]){  // Traverse all the child nodes of the main node
            if(vis[node] && path[node]==1)   return true;// If the node is visited and is also available in the path then return true
            else if(!vis[node]){
                // If node is not visited then visit it and increment in path
                path[node]=1;
                if(dfs(node,adj,vis,path))   return true;
                path[node]=0;// After returning from the path clear the node from the path
            }
        }
        return false; 
    }
    
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                vector<int>path(V,0);// Create a separate path that we are going to traverse
                path[i]=1; // Increment the node in path
                if(dfs(i,adj,vis,path))   return true;
                path[i]=0; // On returning clear the path node
            }
        }
        return false;
    }
};
