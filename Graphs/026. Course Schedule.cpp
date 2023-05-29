class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        //code here
        vector<int>ans,degree(n,0),temp;
	    vector<vector<int>>adj(n);
	    
	    for(int i=0;i<m;i++)
	        adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
	    
	    queue<int>ind;
	    for(int i=0;i<n;i++)
	        for(auto it:adj[i])
	            degree[it]++;// Calculating Indegree of every node
	    
	    for(int i=0;i<n;i++)
	        if(degree[i]==0)
	            ind.push(i);// Pushing nodes in the queue having Indegree as zero
	            
	   while(!ind.empty()){
            // Code here is similar to BFS traversal in trees
            int f=ind.front();
            ind.pop();
            ans.push_back(f);
            
            for(auto it:adj[f]){
                degree[it]--; // Reducing the Indegree at every time we are traversing it
                if(degree[it]==0) // If the Indegree becomes 0
                    ind.push(it); // We push it in the queue
            }
	   }
	   
	   reverse(ans.begin(),ans.end());
	   
	   return (ans.size()<n)?temp:ans; // If the sort is less than the total nodes then it means we have got a cycle in graph and we can't print the ans
    }
};
