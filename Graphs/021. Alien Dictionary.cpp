class Solution{
    public:
    bool dfs(char ind, map<char,vector<char>>& adj,vector<int>&vis,vector<int> &path,vector<vector<char>> &tot){
        vis[ind-'a']=path[ind-'a']=1;
        int maxd=0;

        for(auto node:adj[ind]){  // Traverse all the child nodes of the main node
            if(vis[node-'a'] && path[node-'a']==1)   return true;
            else if(!vis[node-'a']){
                if(dfs(node,adj,vis,path,tot))   return true;
            }
            maxd=max(maxd,vis[node-'a']); // We are using this to check the depthness of current node from its child node's depthness
        }
        
        vis[ind-'a']=maxd+1; // We are updating the depthness in visited array as to remember and save it for other nodes
        tot[maxd+1].push_back(ind);
        path[ind-'a']=0;
        return false; 
    }
    
    string findOrder(string dict[], int n, int K) {
        //code here
        vector<int>vis(K,0); // We are using visited array for double purposes here first we are using it for storing visited array with no. other than 0
                             // and second we are using it store the maximum depth/height of current node from the terminal node
        string ans;
        vector<vector<char>>tot(K+1);// tot array is used for storing nodes according to their depth/height from terminal node
        map<char,vector<char>>adj;
        
        for(int i=0;i<n-1;i++)
            for(int j=0;j<min(dict[i].size(),dict[i+1].size());j++)
                if(dict[i][j]!=dict[i+1][j]){ // Finding the first index where strings differ   
                    adj[dict[i][j]].push_back(dict[i+1][j]); // Building a adjacency graph by taking the first index where both the strings differ and store
                                                             // it in a graph and break.
                    break;
                }

        for(int i=0;i<K;i++){
            if(vis[i])  continue;
            vector<int>path(K,0);// Checking whether there is cycle in directed graph or not
            dfs(i+'a',adj,vis,path,tot);
        }

        for(int i=K;i>0;i--)
            for(auto it:tot[i])// Here we put node in ans depth wise 
                ans.push_back(it);
        
        return ans;
    }
};

/* Note: This question is very similar to the previous solve question no. 019 (Courses 2) we have just replaced indexes like ind with ind-'a' and
         we had built adjacency graph a bit differenly. Read Comments!
*/
