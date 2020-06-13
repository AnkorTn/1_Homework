#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    //TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}*tree[100000];
int ans = 1;
int depth(TreeNode* root){
	if (root == NULL) return 0;
	int left  = depth(root->left);
	int right = depth(root->right);
	ans = max(ans, left+right+1);
	return max(left, right)+1;
}
// In this problem I suppose the vertex 1 is the root vertex.
int main(){
	int n, a, b;
	cin>>n;
	for(int i=1;i<=n;i++){
		tree[i] = new TreeNode;
		tree[i]->left=NULL;
		tree[i]->right=NULL;
		tree[i]->val=i;
	}		
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		tree[i]->left = tree[a];
		tree[i]->right= tree[b];
	}
	for(int i=1;i<=n;i++)
		depth(tree[i]);
	ans --;
	cout<<ans<<endl;
	return 0;
}
