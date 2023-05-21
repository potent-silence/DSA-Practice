class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int n=image.size(),m=image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>ind;// Creating a queue to store indexes while traversing level wise
        ind.push({sr,sc});
        int comp=image[sr][sc];
        while(!ind.empty()){
            // Code here is similar to BFS traversal in trees
            pair<int,int> f=ind.front();
            int row=f.first,col=f.second;
            ind.pop();
            if(vis[row][col])   continue;
            vis[row][col]=1;
            image[row][col]=newColor;// Assign the newly visited node newColor
            
            if(row<n-1 && image[row+1][col]==comp) ind.push({row+1,col}); // Below
            if(row>0 && image[row-1][col]==comp) ind.push({row-1,col}); // Up
            if(col<m-1 && image[row][col+1]==comp) ind.push({row,col+1});; //Left
            if(col>0 && image[row][col-1]==comp) ind.push({row,col-1}); //Right
        }
        return image;
    }
};

/* Approach:
  Just think it as traversing the side by elements of given index and whether they satisfy the given conditions in given constraints.
*/
