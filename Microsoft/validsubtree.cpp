TreeNode* 	validsubtree(TreeNode *root, int &cnt, int start, int end){

	if(root==NULL)
		return root;


	if(root->val > end)
		validsubtree(root->left);
	else if(root->val<start)
		valid(root->right);
	else{
		validsubtree(root->right);
		validsubtree(root->left);
	}

	if(root->left==NULL)
		return root->right;
	if(root->left==NULL)
		return root->left;
	else
		return root;
}

int main(){
	int cnt=0;
	validsubtree(root,cnt,5,20);

}
