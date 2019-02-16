//2019.2.16 18:56
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn = 105;
struct Tree{
	int data;
	int left, right;
}tree[maxn];
int seq[maxn], n, index = 0;
void in_order(int root){
	if(root == -1) return;
	in_order(tree[root].left);
	tree[root].data = seq[index++];
	in_order(tree[root].right);
}
void BFS(int root){
	queue<int> q;
	q.push(root);
	int num = 0;
	while(!q.empty()){
		int now;
		now = q.front();
		q.pop();
		if(num++) cout<<" ";
		cout<<tree[now].data;
		if(tree[now].left != -1) 
			q.push(tree[now].left);
		if(tree[now].right != -1)
			q.push(tree[now].right);	
	}
}
int main(){
	cin>>n;
	for(int i = 0; i < n; ++i)
		cin>>tree[i].left>>tree[i].right;
	for(int i = 0; i < n; ++i)
		cin>>seq[i];
	sort(seq, seq + n);
	in_order(0);
	BFS(0);
	return 0;
}
