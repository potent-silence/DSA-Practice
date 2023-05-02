#include <bits/stdc++.h> 
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
	// Space optimized solution
    vector<int>dp={triangle[0][0]};
    for(int i=1;i<n;i++){
		int m=triangle[i].size();
        vector<int>cur(m,0);// Temp array to store the values of current traversing
        for(int j=0;j<m;j++){
			if(j==0)	cur[j]=dp[j];// If we are at starting index we will just have previous above index
			else if(j==m-1)	cur[j]=dp[j-1]; //If we are at ending index we will just have previous diagonal index
			else	cur[j]=min(dp[j],dp[j-1]);// When we are middle we have both the above options and we choose the one which is minimum.
            cur[j]+=triangle[i][j];
        }
        dp=cur;
    }
    return *min_element(dp.begin(),dp.end());
}
