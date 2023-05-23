class Solution {
public:
    bool dfs(int ind, vector<vector<int>>& adj,vector<int>&vis,vector<int> &path,vector<vector<int>> &tot){
        vis[ind]=path[ind]=1; // We assign vis[ind] value here although we can assign it at Line 17 too because if the function results true before going 
                              // to last function line then we can't get a correct answer and we will get trap with a runtime error.
        int maxd=0; // To measure depthness

        for(auto node:adj[ind]){  // Traverse all the child nodes of the main node
            if(vis[node] && path[node]==1)   return true;
            else if(!vis[node]){
                if(dfs(node,adj,vis,path,tot))   return true;
            }
            maxd=max(maxd,vis[node]); // We are using this to check the depthness of current node from its child node's depthness and taking the maximum
                                      // depthness that is possible for our current node as it assures us that all its child nodes are after this level 
                                      // of depthness and there is no conflict between them regarding depthness.
        }
        
        vis[ind]=maxd+1; // We are updating the depthness in visited array as to remember and save it for other nodes
        tot[maxd+1].push_back(ind); // We are pushing the index at its correct depthness
        path[ind]=0;
        return false; 
    }

    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int>ans,vis(n,0); // We are using visited array for double purposes here first we are using it for storing visited array with no. other than 0 for 
        // to mark them as visited and second we are using it store the maximum depth/height of current node from the terminal node.
        vector<vector<int>>adj(n),tot(n+1);// tot array is used for storing nodes according to their depth/height from terminal node

        for(int i=0;i<pre.size();i++)   adj[pre[i][0]].push_back(pre[i][1]);// Build a adjacency graph

        for(int i=0;i<n;i++){
            if(vis[i])  continue;
            vector<int>path(n,0);// Checking whether there is cycle in directed graph or not
            if(dfs(i,adj,vis,path,tot))   return {};
        }

        for(int i=1;i<=n;i++)
            for(auto it:tot[i])// Here we put node in ans depth wise 
                ans.push_back(it);
                    
        return ans;
    }
};

/*Note:
    As there are some unmentioned elements/courses in prerequisites array so they do not get involved in adjacency graph and hence we can't say anything
    about their depthness but in the program the code is done in the way that all those unmentioned courses get depthness as 1 and we get our ans correct.
    */
