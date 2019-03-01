//2019/3/1 17:06
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 10500;
int m, n;
int in[maxn], pre[maxn];
struct Node{
	int data;
	Node *left, *right;
	bool vis1, vis2;
};
Node* sort(int preLeft, int preRight, int inLeft, int inRight){
	if(preLeft > preRight) return NULL;
	Node* node = new Node;
	node->data = pre[preLeft];
	int inRoot;
	for(inRoot = inLeft; inRoot <= inRight && in[inRoot] != pre[preLeft]; ++inRoot);
	int leftNum = inRoot - inLeft;
	node->left = sort(preLeft + 1, preLeft + leftNum, inLeft, inRoot - 1);
	node->right = sort(preLeft + leftNum + 1, preRight, inRoot + 1, inRight);
	return node;
}
bool postOrder(Node* root, int u, int tag){
	if(root == NULL) return false;
	int lFlag = postOrder(root->left, u, tag);
	int rFlag = postOrder(root->right, u, tag);
	if(root->data == u){
		if(tag == 0) root->vis1 = false;
		else root->vis2 = false;
		return true;
	}
	if(lFlag || rFlag){
		if(tag == 0) root->vis1 = true;
		else root->vis2 = true;
		return true;
	}
	return false;
}
void initial(Node* root){
	if(root == NULL) return ;
	root->vis1 = false;
	root->vis2 = false;
	if(root->left) initial(root->left);
	if(root->right) initial(root->right);
}
queue<Node*> q;
void BFS(Node* root, int u, int v){
	int ans;
	q.push(root);
	while(!q.empty()){
		Node* now = q.front();
		q.pop();
		if(now->vis2 && now->data == u){
			printf("%d is an ancestor of %d.\n", u, v);
			return ;
		}
		else if(now->vis1 && now->data == v){
			printf("%d is an ancestor of %d.\n", v, u);
			return ;
		}
		if(now->vis1 && now->vis2) ans = now->data;
		if(now->left) q.push(now->left);
		if(now->right) q.push(now->right);
	}
	printf("LCA of %d and %d is %d.\n", u, v, ans);
}
int main(){
	scanf("%d %d", &m, &n);
	for(int i = 0; i < n; ++i){
		int temp;
		scanf("%d", &temp);
		in[i] = temp;
	}
	for(int i = 0; i < n; ++i){
		int temp;
		scanf("%d", &temp);
		pre[i] = temp;
	}
	Node* root = sort(0, n - 1, 0, n - 1);
	for(int i = 0; i < m; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		initial(root);
		bool flag1 = postOrder(root, u, 0);
		bool flag2 = postOrder(root, v, 1);
		if(!flag1 && !flag2) printf("ERROR: %d and %d are not found.\n", u, v);
		else if(!flag1) printf("ERROR: %d is not found.\n", u);
		else if(!flag2) printf("ERROR: %d is not found.\n", v);
		else{
			while(!q.empty()) q.pop();
			BFS(root, u, v);
		}
	}
	return 0;
}
