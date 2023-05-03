#include <bits/stdc++.h> 
int getMaxPathSum(vector<vector<int>> &matrix)
{
    // Space optimized code
    vector<int>dp(matrix[0].begin(),matrix[0].end());  
    int n=matrix.size(),m=matrix[0].size();
    for(int i=1;i<n;i++){
        vector<int>now(m,0);
        for(int j=0;j<m;j++){
            if(j==0 && j!=m-1)  now[j]=max(dp[j],dp[j+1]);// If index is starting index then only consider previous above and right diagonal indexes.
            else if(j==m-1 && j!=0) now[j]=max(dp[j],dp[j-1]);// If index is ending one then only consider previous above and left diagonal indexes.
            else if(m==1)   now[j]=dp[j];// If row size is 1 then only consider previous above index
            else    now[j]=max(dp[j],max(dp[j-1],dp[j+1]));// Here consider all the above possible given indexes when you are in middle of array.
            now[j]+=matrix[i][j];
        }
        dp=now;
    }
    return *max_element(dp.begin(),dp.end());
}
