#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	// Write your code here.
	vector<int>ans(m,1);
	for(int i=1;i<n;i++){
		vector<int>temp(m,1);
		for(int j=1;j<m;j++)	temp[j]=temp[j-1]+ans[j];
		// Previous paths are added above in a prefix style
		ans=temp;
	}
	return ans[m-1];
}
