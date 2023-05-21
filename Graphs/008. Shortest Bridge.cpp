class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int ans=INT_MAX,n=grid.size(),m=grid[0].size(),flag=1;
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<int>delrow={-1,0,1,0},delcol={0,1,0,-1};// Making vector of changes of rows and cols during traversing adjacent horizontal and vertical nodes
        vector<pair<int,int>>island1,island2;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] || grid[i][j]==0)  continue; // If it is visited or water
                queue<pair<int,int>>ind;// Creating a queue to store indexes while traversing level wise
                ind.push({i,j});
                
                while(!ind.empty()){
                    // Code here is similar to BFS traversal in trees
                    pair<int,int> f=ind.front();
                    ind.pop();
                    int l=0;
                    for(int i=0;i<4;i++){
                    // Checking adjacent horizontal and vertical nodes
                        int row=f.first+delrow[i],col=f.second+delcol[i];
                        if(row>=0 && row<n && col>=0 && col<m && grid[row][col]==1 && !vis[row][col]){
                            ind.push({row,col});
                            vis[row][col]=1;
                            l++;
                        }
                    }
                    if(l!=4 && flag)  island1.push_back(f);// Island 1's land which is on boundary
                    else if(l!=4 && !flag)  island2.push_back(f); // Island 2's land which is on boundary
                }
                flag=0;// When we get island 1 info we remove the flag
            }
        }
        
        for(int i=0;i<island1.size();i++){
            // Here we are checking all permutation to find shorter distance
            for(int j=0;j<island2.size();j++)   ans=min(ans,abs(island1[i].first-island2[j].first)+abs(island1[i].second-island2[j].second));
        }

        return ans-1;
    }
};
