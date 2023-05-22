class Solution {
public:
    bool dfs(int ind, vector<vector<int>>& adj,vector<int>&vis,vector<int> &path){
        vis[ind]=1;
        
        for(auto node:adj[ind]){  // Traverse all the child nodes of the main node
            if(vis[node] && path[node]==1)   return true;
            else if(!vis[node]){
                path[node]=1;
                if(dfs(node,adj,vis,path))   return true;
                path[node]=0;
            }
        }
        return false; 
    }

    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>vis(n,0);
        vector<vector<int>>adj(n);

        for(int i=0;i<pre.size();i++)   adj[pre[i][0]].push_back(pre[i][1]);// Build a adjacency graph

        for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<int>path(n,0);
                path[i]=1;
                if(dfs(i,adj,vis,path))   return false;
                path[i]=0;
            }
        }
        return true;
    }
};
