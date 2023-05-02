int minFallingPathSum(vector<vector<int>>& grid) {
    // Space optimized solution
    int n=grid.size(),m=n;
    vector<int>dp(m);
    for(int i=0;i<n;i++){
        vector<int>cur(m,0);// Temp array to store the values
        for(int j=0;j<m;j++){
            if(j>0 && i>0 && j<m-1) cur[j]=min(dp[j],min(dp[j-1],dp[j+1]));// Here we take the minimum of previous above,left and right diagonal indexes
            else if(j==0 && i>0)    cur[j]=min(dp[j],dp[j+1]);// Here we take minimum of above and right diagonal indexes
            else if(j==m-1 && i>0)  cur[j]=min(dp[j],dp[j-1]);// Here we take minimum of above and left diagonal indexes
            cur[j]+=grid[i][j];
        }
        dp=cur;
    }
    return *min_element(dp.begin(),dp.end());
}
