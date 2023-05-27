class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void dfs(int ind, vector<int> adj[],stack<int>&ans,vector<int>&vis){
        vis[ind]=1;// When you visit for the first time mark it as visited
        for(int i=0;i<adj[ind].size();i++)  // Traverse all the child nodes of the main node
            if(!vis[adj[ind][i]])    dfs(adj[ind][i],adj,ans,vis);// If the child node is not visited then visit
        ans.push(ind);// Push the value in stack while returning
    }
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>ans,vis(V,0);
	    stack<int>st;
	    for(int i=0;i<V;i++)
	        if(!vis[i])
                dfs(i,adj,st,vis);
                
        while(!st.empty())  ans.push_back(st.top()),st.pop();
        return ans;
	}
};

/*Approach: 
    It is very simple you are visiting the graph and pushing the element first which you have visted the last and if a index is visited all its element are already 
    pushed earlier than the element before where we are cuurently traversing.
*/
