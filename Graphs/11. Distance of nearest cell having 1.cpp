class Solution 
{
  public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n=grid.size(),m=grid[0].size();
	    vector<vector<int>>ans(n,vector<int>(m,0)),vis(n,vector<int>(m,0));
	    vector<int>delrow={-1,0,1,0},delcol={0,1,0,-1};// Making vector of changes of rows and cols during traversing adjacent horizontal and vertical nodes
	    
	    queue<pair<int,int>>exp; // Queue for storing expanding nodes
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            // Here we are traversing all the 1's in connected components by BFS and storing the boundaries of them.
	            
	            if(vis[i][j] || !grid[i][j])  continue;// If node is visited or node's  value is 0
	            queue<pair<int,int>>ind;
	            ind.push({i,j});
	            while(!ind.empty()){
	                pair<int,int> f=ind.front();
	                ind.pop();
	                int b=0; // This variable is for checking if a node is boundary or not
	                
	                for(int i=0;i<4;i++){
                    // Checking adjacent horizontal and vertical nodes
                        int row=f.first+delrow[i],col=f.second+delcol[i];
                        if(row>=0 && row<n && col>=0 && col<m && grid[row][col]==1 && !vis[row][col]){
                            ind.push({row,col});
                            vis[row][col]=1;
                            b++;
                        }
                    }
                    if(b!=4)    exp.push(f);// All the boundary nodes of connected components are pushed in expanding queue
	            }
	        }
	    }
	    
	    // Now we are expanding all the boundaries in the area of 0's simultaneously
        while(!exp.empty()){
            // Here we are doing BFS from the boundaries of all connected components
            pair<int,int> f=exp.front();
            exp.pop();
            
            for(int i=0;i<4;i++){
            // Checking adjacent horizontal and vertical nodes
                int row=f.first+delrow[i],col=f.second+delcol[i];
                if(row>=0 && row<n && col>=0 && col<m && grid[row][col]==0 && !vis[row][col]){
                    ans[row][col]=ans[f.first][f.second]+1;
                    exp.push({row,col});
                    vis[row][col]=1;
                }
            }
        }
	    return ans;
	}
};

/*Approach: 
  First we are traversing all the 1's using BFS in connected component and storing their boundary nodes in an expand queue. After getting all the boundary
  nodes we traverse them and increase them simultaneously in the territory of 0's. After conquering all the territory of 0's simultaneously we get our ans.
*/
