#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
vector<int> in, post;
struct Node{
	int val, dep;
	Node *left, *right;
};
Node* create(int inL, int inR, int postL, int postR){
	if(inL > inR) return NULL;
	Node* root = new Node;
	root->val = post[postR];
	root->left = root->right = NULL;
	int pla;
	for(pla = inL; pla <= inR; ++pla)
		if(in[pla] == post[postR]) break;
	int leftNum = pla - inL;
	root->left = create(inL, pla - 1, postL, postL + leftNum - 1);
	root->right = create(pla + 1, inR, postL + leftNum, postR - 1);
	return root;
}
vector<Node*> pr;
void levelOrder(Node* root){
	if(root == NULL) return ;
	root->dep = 1;
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node* now = q.front();
		q.pop();
		pr.push_back(now);
		if(now->left){
			now->left->dep = now->dep + 1;
			q.push(now->left);
		}
		if(now->right){
			now->right->dep = now->dep + 1;
			q.push(now->right);
		}
	}
}
void print(){
	bool isReverse = false;
	cout<<pr[0]->val;
	pr.erase(pr.begin());
	while(!pr.empty()){
		if(isReverse){
			isReverse = false;
			int dep = pr[0]->dep;
			int i;
			for(i = 1; i < pr.size(); ++i)
				if(pr[i]->dep != dep) break;
			for(int j = i - 1; j >= 0; --j)
				cout<<" "<<pr[j]->val;
			pr.erase(pr.begin(), pr.begin() + i);
		}
		else{
			isReverse = true;
			int dep = pr[0]->dep;
			int i;
			for(i = 1; i < pr.size(); ++i)
				if(pr[i]->dep != dep) break;
			for(int j = 0; j < i; ++j)
				cout<<" "<<pr[j]->val;
			pr.erase(pr.begin(), pr.begin() + i);
		}
	}
}
int main(){
	int n;
	cin>>n;
	in.resize(n);
	post.resize(n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &in[i]);
	for(int i = 0; i < n; ++i)
		scanf("%d", &post[i]);
	Node* root = create(0, n - 1, 0, n - 1);
	levelOrder(root);
	print();
	return 0;
}
