class Solution {
  public:
  vector<int>delrow={-1,0,1,0},delcol={0,1,0,-1};

    void bfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis) {
        // Code here
        queue<pair<int,int>>ind;// Creating a queue to store indexes while traversing level wise
        ind.push({i,j});
        int n=grid.size(),m=grid[0].size();
        
        while(!ind.empty()){
            // Code here is similar to BFS traversal in trees
            pair<int,int> f=ind.front();
            ind.pop();
            
            for(int i=0;i<4;i++){
            // Checking adjacent horizontal and vertical nodes
                int row=f.first+delrow[i],col=f.second+delcol[i];
                if(row>=0 && row<n && col>=0 && col<m && grid[row][col]==1 && !vis[row][col]){
                    ind.push({row,col});
                    vis[row][col]=1;
                }
            }
        }
    }
    
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if((i==0 || i==n-1 || j==0 || j==m-1) && grid[i][j]==1 && !vis[i][j]){
                    // We are just doing BFS/DFS we get any node 1 on boundary of matrix we mark all the 1's connected to that node as visited
                    bfs(i,j,grid,vis);
                    vis[i][j]=1;
                }
        
        int ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++) 
                if(!vis[i][j] && grid[i][j]==1)
                    ans++; // After we secure all the boundary we search for the 1's that are not visited earlier which in case are the ones that can not exit
        
        return ans;
    }
};
