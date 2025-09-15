#include<bits/stdc++.h>

using namespace std;


class TreeNode
{
	public:
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x){
			val = x;
			left = NULL;
			right = NULL;
		}

};

/*
    5
   / \
 4    7
     / \
    6   8
*/

TreeNode* lcp(TreeNode *root, int p, int q, int &cnt){

	if(root==NULL)
		return NULL;

	if(root->val==p || root->val==q){
		cnt++;
		return root;
	}


	TreeNode *left , *right;
	if(root->val<p && root->val<q){
		left = NULL;
		right = lcp(root->right, p, q, cnt);
	}
	else if(root->val >p && root->val>q){
		left = lcp(root->left, p, q, cnt);
		right = NULL;
	}
	else{
		left = lcp(root->left, p, q, cnt);
		right = lcp(root->right, p, q, cnt);
	}


	if(left==NULL)
		return right;

	else if(right==NULL)
		return left;

	else
		return root;

}


int main(){

	TreeNode *tree = new TreeNode(5);
	tree->left = new TreeNode(4);
	tree->right = new TreeNode(7);
	tree->right->left = new TreeNode(6);
	tree->right->right = new TreeNode(8);

	int cnt=0;

	TreeNode *find = lcp(tree,4,100,cnt);

	auto ans  = find!=NULL?find->val:INT_MIN;
	if(ans!=INT_MIN && cnt==2)
		cout<<"found: "<<ans<<'\n';
	else
		cout<<"not found\n";

}
