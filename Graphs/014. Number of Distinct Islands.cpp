class Solution {
  public:
    vector<int>delrow={-1,0,1,0},delcol={0,1,0,-1};
    
    void dfs(int row,int col, vector<vector<int>>& grid,vector<pair<int,int>> &shape,vector<vector<int>>& vis,int &br,int &bc){
        vis[row][col]=1;// When you visit for the first time mark it as visited
        shape.push_back({row-br,col-bc});// Storing the shape by subtracting the base row and col from the obtained one
        int n=grid.size(),m=grid[0].size();
        
        for(int i=0;i<4;i++){
        // Checking adjacent horizontal and vertical nodes
            int nrow=row+delrow[i],ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol])
                dfs(nrow,ncol,grid,shape,vis,br,bc);
        }
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>>dis;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){ 
                    vector<pair<int,int>> shape; // To store the shape
                    dfs(i,j,grid,shape,vis,i,j);
                    dis.insert(shape);
                }
            }
        }
        
        return dis.size();
    }
};
