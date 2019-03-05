//2019/3/5 16:57
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
struct Node{
	int data;
	Node *left, *right;
};
int pre[50], po[50], in[50];
int findEle(int num[], int n, int left, int right){
	int i;
	for(i = left; i <= right; ++i)
		if(num[i] == n) break;
	return i;
}
bool flag = true;
Node* createTree(int preL, int preR, int poL, int poR){
	if(preL > preR) return NULL;
	Node* root = new Node;
	root->data = pre[preL];
	root->left = root->right = NULL;
	if(preL == preR) return root;
	int poRRoot = poR - 1;
	//judge isSole
	int preRRoot = findEle(pre, po[poRRoot], preL + 1, preR);
	if(preRRoot == preL + 1) flag = false;
	
	int leftNum = preRRoot - preL - 1;
	root->left = createTree(preL + 1, preL + leftNum, poL, poL + leftNum - 1);
	root->right = createTree(preRRoot, preR, poL + leftNum, poR - 1);
	return root;
}
vector<int> p;
void inOrder(Node* root){
	if(root == NULL) return ;
	inOrder(root->left);
	p.push_back(root->data);
	inOrder(root->right);
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &pre[i]);
	for(int i = 0; i < n; ++i)
		scanf("%d", &po[i]);
	Node* root = createTree(0, n - 1, 0, n - 1);
	if(flag) printf("Yes\n");
	else printf("No\n");
	inOrder(root);
	for(int i = 0; i < p.size(); ++i){
		if(i) printf(" ");
		printf("%d", p[i]);
	}
	printf("\n");
	return 0;
}
