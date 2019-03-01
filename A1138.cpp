//2019/3/1 21£º12 
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 50500;
int pre[maxn], in[maxn], n;
struct Node{
	int data;
	Node *left, *right;
};
Node* fun(int preLeft, int preRight, int inLeft, int inRight){
	if(preLeft > preRight) return NULL;
	Node* root = new Node;
	root->data = pre[preLeft];
	int i;
	for(i = inLeft; i <= inRight && in[i] != pre[preLeft]; ++i) ;
	int leftNum = i - inLeft;
	root->left = fun(preLeft + 1, preLeft + leftNum, inLeft, i - 1);
	root->right = fun(preLeft + leftNum + 1, preRight, i + 1, inRight);
	return root;
}
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &pre[i]);
	for(int i = 0; i < n; ++i)
		scanf("%d", &in[i]);
	Node* root = fun(0, n - 1, 0, n - 1);	
	Node* preNode = root;
	while(root->left || root->right){
		if(root->left)
			root = root->left;
		else if(root->right)
			root = root->right;
	}
	printf("%d\n", root->data);
	return 0;
}
 
