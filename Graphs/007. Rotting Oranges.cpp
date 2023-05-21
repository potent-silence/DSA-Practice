class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),ans=0,fresh=0,frot=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>ind;// Creating a queue to store indexes while traversing level wise
        vector<int>delrow={-1,0,1,0},delcol={0,1,0,-1};// Making vector of changes of rows and cols during traversing adjacent horizontal and vertical nodes
        for(int i=0;i<n;i++){
            // Pushing all the initial rotten Oranges in the queue
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)   ind.push({i,j});
                else if(grid[i][j]==1)  fresh++;
            }
        }
        
        while(!ind.empty()){
            // Code here is similar to BFS traversal in trees
            int si=ind.size();
            if(frot!=0) ans++;
            while(si--){
                pair<int,int> f=ind.front();
                ind.pop();
                
                for(int i=0;i<4;i++){
                    // Checking adjacent horizontal and vertical nodes
                    int row=f.first+delrow[i],col=f.second+delcol[i];
                    if(row>=0 && row<n && col>=0 && col<m && grid[row][col]==1 && !vis[row][col]){
                        grid[row][col]=2;
                        ind.push({row,col});
                        vis[row][col]=1;
                        frot++;
                    }
                }
            }
        }
        return (frot==fresh)?ans:-1;
    }
};
