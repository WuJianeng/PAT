//2019.2.14 22:38
#include<cstdio>
#include<iostream>
#include<queue>
#include<string>
using namespace std;
int tree[15][3];//tag, lchild, rchild;
int k = 0;
void in_order(int root){
	if(tree[root][2] != -1) in_order(tree[root][2]);
	if(k) printf(" ");
	printf("%d", root);
	k++;
	if(tree[root][1] != -1) in_order(tree[root][1]);
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		tree[i][0] = 0;	//root node;
		tree[i][1] = -1;
		tree[i][2] = -1;
	}
	
	//initial static BinaryTree
	for(int i = 0; i < n; ++i){
		int L = -1, R = -1;
		string str;
		cin>>str;
		if(str != "-") L = str[0] - '0';
		cin>>str;
		if(str != "-") R = str[0] - '0';
		if(L >= 0){
			tree[i][1] = L;
			tree[L][0] = 1;//not root node
		}
		if(R >= 0){
			tree[i][2] = R;
			tree[R][0] = 1;
		}
	}
	//find root with tag = 0;
	int root;
	for( root = 0; root < n; ++root)
		if(tree[root][0] == 0) break;
	//use a queue to get level-order(inverse)
	queue<int> q;
	q.push(root);
	int count = 0;//numbers that has been poped from queue
	while(!q.empty()){
		int now = q.front();
		q.pop();
		count++;
		if(count != 1) printf(" ");
		printf("%d", now);
		if(tree[now][2] != -1) q.push(tree[now][2]);
		if(tree[now][1] != -1) q.push(tree[now][1]);
	}
	printf("\n");
	// in-order inverse
	in_order(root);
	printf("\n");
	return 0;
}
