class Solution{
public:
    vector<int>delrow={-1,0,1,0},delcol={0,1,0,-1};

    void bfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& vis) {
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
                if(row>=0 && row<n && col>=0 && col<m && grid[row][col]=='O' && !vis[row][col]){
                    ind.push({row,col});
                    vis[row][col]=1;
                }
            }
        }
    }
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if((i==0 || i==n-1 || j==0 || j==m-1) && mat[i][j]=='O' && !vis[i][j]){
                    // We are just doing BFS/DFS we get any node 'O' on boundary of matrix
                    bfs(i,j,mat,vis);
                    vis[i][j]=1;
                }
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++) 
                if(!vis[i][j] && mat[i][j]=='O')
                    mat[i][j]='X'; // After we secure all the boundary we change the remaining 'O' to 'X'
        
        return mat;
    }
};

/* Approach:
  As the O's near to the boundary will be the only one who will not be surrounded by X's so visit all the O's that are connected to the boundary
  and change the remaining O's to X's
  */
