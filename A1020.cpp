//2019.2.14 20:25 forked from Qingshen Notes
#include<cstdio>
#include<queue>
using namespace std;
const int maxn = 50;
int post[maxn], in[maxn];
int n;
struct Node{
	int data;
	Node *lchild, *rchild;
};
Node* create(int post_l, int post_r, int in_l, int in_r){
	if(post_l > post_r) return NULL;
	Node* root = new Node;
	root->data = post[post_r];
	int place;
	for(int i = in_l; i <= in_r; ++i){
		if(in[i] == post[post_r] ){
			place = i;
			break;
		}
	}
	int num_l = place - in_l;
	root->lchild = create(post_l, post_l + num_l - 1, in_l, place - 1);
	root->rchild = create(post_l + num_l, post_r - 1, place + 1, in_r);
	return root;
}
void BFS(Node* root){
	queue<Node*> q;
	q.push(root);
	int i = 0;
	while(!q.empty()){
		if(i) printf(" ");
		Node* p = q.front();
		q.pop();
		printf("%d", p->data);
		if(p->lchild) q.push(p->lchild);
		if(p->rchild) q.push(p->rchild);
		i++;
	}
	printf("\n");
	return ;
}
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &post[i]);	
	for(int i = 0; i < n; ++i)
		scanf("%d", &in[i]);	
	Node* root = create(0, n - 1, 0, n - 1);
	BFS(root);
	return 0;
}
