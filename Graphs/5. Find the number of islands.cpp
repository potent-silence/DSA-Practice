class Solution {
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // your code goes here
        
        int ans=0,n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] || grid[i][j]=='0')  continue; // If it is visited or water
                ans++;// If the node is not visited earlier in any traversal then we are getting a new province
                queue<pair<int,int>>ind;// Creating a queue to store indexes while traversing level wise
                ind.push({i,j});
                
                while(!ind.empty()){
                    // Code here is similar to BFS traversal in trees
                    pair<int,int> f=ind.front();
                    ind.pop();
                    
                    for(int drow=-1;drow<=1;drow++){
                        for(int dcol=-1;dcol<=1;dcol++){
                            int row=f.first+drow,col=f.second+dcol;
                            if(row>=0 && row<n && col>=0 && col<m && grid[row][col]=='1' && !vis[row][col]){
                                // We are checking if row and col is in constraints,its land and not visited
                                ind.push({row,col});
                                vis[row][col]=1;
                            }
                        }
                    }
                }
            }
        }
        
    return ans;
    }
};
