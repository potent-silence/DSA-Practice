class Solution{
    public:
    string findOrder(string dict[], int n, int K) {
        //code here
        string ans;
        map<char,vector<char>>adj;
        vector<int>degree(K,0);
        queue<char>ind;
        
        for(int i=0;i<n-1;i++)
            for(int j=0;j<min(dict[i].size(),dict[i+1].size());j++)
                if(dict[i][j]!=dict[i+1][j]){    
                    adj[dict[i][j]].push_back(dict[i+1][j]); // Build a adjacency graph
                    degree[dict[i+1][j]-'a']++;
                    break;
                }
        
        for(int i=0;i<K;i++)
	        if(degree[i]==0)
	            ind.push('a'+i);// Pushing nodes in the queue having Indegree as zero
	            
	    while(!ind.empty()){
	        char f=ind.front();
	        ind.pop();
	        ans.push_back(f);
	        
	        for(auto it:adj[f]){
	            degree[it-'a']--;
	            if(degree[it-'a']==0)   ind.push(it);
	        }
	    }
	    
	    return ans;
    }
};
