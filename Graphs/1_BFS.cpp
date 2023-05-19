class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>ans,visited(V,0);// Creating ans and visited array to mark the visited nodes
        queue<int>indexes;// Creating a queue to store indexes while traversing level wise
        indexes.push(0);
        while(!indexes.empty()){
            // Code here is similar to BFS traversal in trees
            int f=indexes.front();
            indexes.pop();
            if(visited[f])  continue;// If node is traversed continue to next node
            ans.push_back(f);// Add the current unvisited node to ans
            visited[f]=1;// Mark the visited node
            for(int i=0;i<adj[f].size();i++)    indexes.push(adj[f][i]);// Adding nodes in the queue that are not traversed
        }
        return ans;
    }
};
