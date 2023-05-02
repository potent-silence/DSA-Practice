int minFallingPathSum(vector<vector<int>>& grid) {
        // Space optimized solution
        // This question is solved with keeping similar logic to ninja's training question
        int n=grid.size(),m=n;
        vector<int>dp(grid[0].begin(),grid[0].end());
        for(int i=1;i<n;i++){
            vector<int>now(m,0);// Temp array to store the values
            for(int cur=0;cur<m;cur++){
                // We are taking a current index and checking all the past row indexes leaving the current one
                int mini=INT_MAX;
                for(int last=0;last<m;last++){
                    // Here we are checking the minimum of all the past row indexes leaving the current one
                    if(last!=cur){
                        if(dp[last]<mini)   mini=dp[last];
                    }
                }
                now[cur]=grid[i][cur]+mini;// We add the current index with the lowest past row index
            }
            dp=now;
        }
        return *min_element(dp.begin(),dp.end());
    }
