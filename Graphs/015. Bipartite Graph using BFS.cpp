class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int>vis(V,0);
	    for(int i=0;i<V;i++){
	        if(vis[i]!=0)  continue;
	        queue<int>ind;
	        ind.push(i);
	        
	        while(!ind.empty()){
	            int f=ind.front();
	            ind.pop();
	            
	            if(vis[f]==0){
	                // We come here only when we are at starting node and we intialize the process of coloring
	                vis[f]=1;
	                for(auto it:adj[f]){
	                    ind.push(it);
	                    vis[it]=-1;
	                }
	            }
	            else{
	                for(auto it: adj[f]){
	                    if(vis[it]!=0){
	                        if(vis[it]==vis[f]) return false; //If the current node and next node both have same color then return false
	                    }
	                    else{
	                        // If node is not color give it opposite color to the current one
	                        ind.push(it);
	                        vis[it]=-vis[f];
	                    }
	                }
	            }
	        }
	    }
	    
	    return true;
	}
};
