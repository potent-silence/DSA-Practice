class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int src){
        // code here
        vector<int>ans(n,INT_MAX),vis(n,0);
        vector<vector<int>>adj(n);
        for(int i=0;i<m;i++){ // Creating a adjacency graph
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        ans[src]=0; // Marking the starting source as 0
        queue<int>ind;
        ind.push(src); // Because starting node is 0
        while(!ind.empty()){
            // Code here is similar to BFS traversal in trees
            int f=ind.front();
            ind.pop();
            
            for(auto it:adj[f]){
                if(!vis[it] && it!=f){ 
                    ind.push(it); // We push it in the queue
                    vis[it]=1;
                }
                ans[it]=min(ans[it],ans[f]+1);// Comparing the shortest path possible, even if its visited or not 
            }
	   }
	   
	   for(int i=0;i<ans.size();i++)
	        if(ans[i]==INT_MAX)
	            ans[i]=-1; // The nodes which have INT_MAX as answer are the ones where we cant reach
	   
	   return ans;
    }
};
