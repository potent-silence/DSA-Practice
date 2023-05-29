class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>ans,degree(V,0);
	    queue<int>ind;
	    for(int i=0;i<V;i++)
	        for(auto it:adj[i])
	            degree[it]++;// Calculating Indegree of every node
	    
	    for(int i=0;i<V;i++)
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
	   
	   return ans;
	}
};
