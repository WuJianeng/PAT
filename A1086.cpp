//2019.2.14 21:30
#include<cstdio>
#include<iostream>
#include<string>
#include<stack>
using namespace std;
struct Node{
	int data;
	Node *lchild, *rchild;
};
int pre[35], in[35];
void initial(int n){
	stack<int> s;
	string str;
	int temp, numP = 0, numI = 0;
	while(n){
		cin>>str;
		if(str == "Push"){
			cin>>temp;
			s.push(temp);
			pre[numP++] = temp;
		}
		else{
			in[numI++] = s.top();
			s.pop();
			n--;
		}
	}
}
Node* create(int preL, int preR, int inL, int inR){
	if(preL > preR) return NULL;
	Node* root = new Node;
	root->data = pre[preL];
	int place;
	for(place = inL; place<= inR; ++place)
		if(in[place] == pre[preL]) break;
	int numL = place - inL;
	root->lchild = create(preL + 1, preL + numL, inL, place - 1);
	root->rchild = create(preL + numL + 1, preR, place + 1, inR);
	return root;
}
int i = 0;
void post_print(Node* root){
	if(root == NULL) return ;
	if(root->lchild) post_print(root->lchild);
	if(root->rchild) post_print(root->rchild);
	if(i) printf(" ");
	printf("%d", root->data);
	i++;
}
int main(){
	int n;
	scanf("%d", &n);
	initial(n);
	Node* root = create(0, n - 1, 0, n - 1);
	post_print(root);
	return 0;
}
