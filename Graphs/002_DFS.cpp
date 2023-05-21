class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int ind, vector<int> adj[],vector<int>&ans,vector<int>&vis){
        vis[ind]=1;// When you visit for the first time mark it as visited
        ans.push_back(ind);// Update it in your ans
        for(int i=0;i<adj[ind].size();i++)  // Traverse all the child nodes of the main node
            if(!vis[adj[ind][i]])    dfs(adj[ind][i],adj,ans,vis);// If the child node is not visited then visit
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>ans,vis(V,0);
        dfs(0,adj,ans,vis);// Recursive Approach
        return ans;
    }
};
