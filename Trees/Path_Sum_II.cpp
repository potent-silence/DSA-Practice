void solve(TreeNode* root, int &target,vector<vector<int>>&ans,vector<int>&ele,int sum){
    if(sum+(root->val)==target && root->left==NULL && root->right==NULL){ 
        // We check here whether the node is leaf and the sum matches the target
        ele.push_back(root->val);
        ans.push_back(ele);
        ele.pop_back();
        return;
    }

    if(root->left!=NULL){
        ele.push_back(root->val);
        solve(root->left,target,ans,ele,sum+root->val);
        ele.pop_back();
    }
    if(root->right!=NULL){
        ele.push_back(root->val);
        solve(root->right,target,ans,ele,sum+root->val);
        ele.pop_back();
    }
}

vector<vector<int>> pathSum(TreeNode* root, int target) {
    vector<vector<int>>ans;
    if(root==NULL)  return ans;
    vector<int>ele;
    solve(root,target,ans,ele,0);
    return ans;
}
