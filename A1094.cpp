//2019 2.16 12:56
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 105;
struct Tree{
	int level;
	vector<int> child;
	bool isRoot;
}tree[maxn];
int main(){
	int n, m;
	cin>>n>>m;
	for(int i = 1; i <= n; ++i)
		tree[i].isRoot = true;
	for(int i = 0; i < m; ++i){
		int id, k;
		cin>>id>>k;
		for(int j = 0; j < k; ++j){
			int child;
			cin>>child;
			tree[id].child.push_back( child );
			tree[child].isRoot = false;
		}
	}
	//get root
	int root;
	for(root = 1; root <= n; ++root)
		if(tree[root].isRoot == true) break;
	//BSF
	queue<int> q;
	q.push(root);
	int level[150] = {0};
	tree[root].level = 1;
	level[1]++;
	while(!q.empty() ){
		int now = q.front();
		q.pop();
		for(int j = 0; j < tree[now].child.size(); ++j){
			int child = tree[now].child[j];
			tree[child].level = tree[now].level + 1;
			level[ tree[child].level ]++;
			q.push(child);
		}
	}
	int count = 0, le;
	for(int i = 1; i < n + 5; ++i)
		if(level[i] > count){
			count = level[i];
			le = i;
		}
	cout<<count<<" "<<le<<endl;	
}
