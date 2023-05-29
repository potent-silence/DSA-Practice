class Solution {
  public:
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        // code here
        vector<int>ans(n,INT_MAX),degree(n,0);
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            if(degree[edges[i][0]]>0 || edges[i][0]==0) degree[edges[i][1]]++;// We are incremented the degree of a node only if it is coming from node 0
        }
        
        ans[0]=0;
        queue<int>ind;
        ind.push(0);
        while(!ind.empty()){
            // Code here is similar to BFS traversal in trees
            int f=ind.front();
            ind.pop();
            
            for(auto it:adj[f]){
                degree[it.first]--; // Reducing the Indegree at every time we are traversing it
                if(degree[it.first]==0) // If the Indegree becomes 0
                    ind.push(it.first); // We push it in the queue
                
                ans[it.first]=min(ans[it.first],ans[f]+it.second);// Comparing the shortest path possible, even if degree is 0 or not 
            }
	   }
	   
	   for(int i=1;i<ans.size();i++)
	        if(ans[i]==INT_MAX)
	            ans[i]=-1; // The nodes which have INT_MAX as answer are the ones where we cant reach
	   
	   return ans;
    }
};
