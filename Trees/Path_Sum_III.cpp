void solve(TreeNode* root, int &target,int &ans,long sum){
    if(sum+(root->val)==target) ans++;

    if(root->left!=NULL){
        solve(root->left,target,ans,sum+root->val);
        solve2(root->left,target,ans,0);// Making Subtree for every node
    }
    if(root->right!=NULL){
        solve(root->right,target,ans,sum+root->val);
        solve2(root->right,target,ans,0);// Making Subtree for every node
    }
}

void solve2(TreeNode* root, int &target,int &ans,long sum){
    // This function doesn't create more sub-trees and calculate the sum of all paths equal to target once only 
    if(sum+(root->val)==target) ans++;
    if(root->left!=NULL)    solve2(root->left,target,ans,sum+root->val);
    if(root->right!=NULL)   solve2(root->right,target,ans,sum+root->val);
}

int pathSum(TreeNode* root, int target) {
    int ans=0;
    if(root==NULL)  return ans;
    solve(root,target,ans,0);
    return ans;
}
