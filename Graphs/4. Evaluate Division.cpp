class Solution {
public:
    void dfs(string ind,map<string,vector<pair<string,double>>>&mp,vector<double>&ans,unordered_map<string,int>&vis,double val,string &che){
        vis[ind]=1;
        if(ind==che){
            if(!(mp.find(che)==mp.end()))   ans.push_back(val);
            else    ans.push_back(-1);// If start node is equal to end node but node is not found in original graph
            return;
        }
        for(auto it:mp[ind])
            if(!vis[it.first])    dfs(it.first,mp,ans,vis,val*it.second,che);
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string,vector<pair<string,double>>>mp;// We are making a bi-directional weighted graph here
        vector<double>ans;
        int n=equations.size();
        for(int i=0;i<n;i++){
            // Below are two edges between same vertices with different directed weights
            mp[equations[i][0]].push_back({equations[i][1],values[i]});
            mp[equations[i][1]].push_back({equations[i][0],1/values[i]});
        }
        
        for(int i=0;i<queries.size();i++){
            unordered_map<string,int>vis;
            double val=1;
            dfs(queries[i][0],mp,ans,vis,val,queries[i][1]);
            if(!vis[queries[i][1]]) ans.push_back(-1);// If the end node is not visited than assign -1
        }
        return ans;
    }
};
