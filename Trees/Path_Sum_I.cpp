bool solve(TreeNode* root, int &target,int sum){
    if(sum+(root->val)==target && root->left==NULL && root->right==NULL){ 
        // We check here whether the node is leaf and the sum matches the target
        return 1;
    }
    bool left=0,right=0;
    if(root->left!=NULL)    left=solve(root->left,target,sum+root->val);// If we find the sum in left subtree
    if(root->right!=NULL)   right=solve(root->right,target,sum+root->val);// If we find the sum in right subtree
    return left|right;
}

bool hasPathSum(TreeNode* root, int target) {
    if(root==NULL)  return 0;
    return solve(root,target,0);
}
