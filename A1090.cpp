//2019.2.15 0:37
#include<cstdio>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn = 100100;
struct Tree{
	int depth;
	bool tag;
	vector<int> child;
}tree[maxn];
int BFS(int root, double p, double r){
	queue<int> q;
	q.push(root);
	tree[root].depth = 0;
	int dep;
	double price = 0;
	while(!q.empty()){
		int temp = q.front();
		dep = tree[temp].depth + 1;
		q.pop();
		for(vector<int>::iterator it = tree[temp].child.begin(); it != tree[temp].child.end(); ++it){
			q.push(*it);
			tree[*it].depth = dep;
		}
	}
	return --dep;
}
int main(){
	int n, root;
	double p, r;
	scanf("%d %lf %lf", &n, &p, &r);
	for(int i = 0; i < n; ++i)
		tree[i].tag = true;
	for(int i = 0; i < n; ++i){
		int k;
		scanf("%d", &k);
		if(k == -1)
			root = i;
		else{
			tree[k].child.push_back(i);
			tree[k].tag = false;
		}
	}
	int count = 0;
	int dep = BFS(root, p, r);
	double price = pow(1 + r / 100, dep) * p;
	for(int i = 0; i < n; ++i)
		if(tree[i].depth == dep) count++;
	printf("%.2f %d\n", price, count);
	return 0;
}
