int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    vector<int>ans(m,0);
    int mod=1e9+7;
	for(int i=0;i<n;i++){
		vector<int>temp(m,0);
        if(i==0)    temp[0]=1;
		for(int j=0;j<m;j++){	
            if(mat[i][j]==-1){ 
                // If path is block mark the ans as zero  
                temp[j]=0;
                continue;
            }
            if(j>0) temp[j]=(temp[j-1]%mod);// If right path exists copy it
            if(i>0) temp[j]+=(ans[j]%mod);// If above path exists append it
            temp[j]%=mod;
        }
		ans=temp;
	}
	return ans[m-1];
}
