class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int ans=0;
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(vis[i])  continue;
            ans++;// If the node is not visited earlier in any traversal then we are getting a new province
            queue<int>indexes;// Creating a queue to store indexes while traversing level wise
            indexes.push(i);
            while(!indexes.empty()){
                // Code here is similar to BFS traversal in trees
                int f=indexes.front();
                indexes.pop();
                if(vis[f])  continue;// If node is traversed continue to next node
                vis[f]=1;// Mark the visited node
                for(int i=0;i<adj[f].size();i++)    
                    if(adj[f][i]==1)    indexes.push(i);// Adding nodes in the queue that are not traversed
            }
        }
        return ans;
    }
};


/*Approach:
  We are just traversing the graph at each node with bfs and marking all the visited ones. If we go on traversing and get a node which not been traversed in earlier bfs traversal then we have got a new province.
 */
