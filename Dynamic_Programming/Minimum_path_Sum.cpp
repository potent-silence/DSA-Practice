#include <bits/stdc++.h> 
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    // Space optimized solution
    int n=grid.size(),m=grid[0].size();
    vector<int>dp(m);
    for(int i=0;i<n;i++){
        vector<int>cur(m,0);// Temp array to store the values
        for(int j=0;j<m;j++){
            if(j>0 && i>0) cur[j]=min(dp[j],cur[j-1]);// If both left and above part is there then take the minimum
            else if(i==0 && j>0)    cur[j]=cur[j-1];// If any left part is there then append
            else if(j==0 && i>0)    cur[j]=dp[j];// If any above part is there then append
            cur[j]+=grid[i][j];
        }
        dp=cur;
    }
    return dp[m-1];
}
