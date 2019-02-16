//2019.2.16 14:19
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 105;
struct Tree{
	int level;
	bool isNo_leaf;
	vector<int> child;
}tree[maxn];
int main(){
	int n, m;
	cin>>n>>m;
	for(int i = 1; i <= n; ++i)
		tree[i].isNo_leaf = true;
	for(int i = 0; i < m; ++i){
		int id, k;
		cin>>id>>k;
		tree[id].isNo_leaf = false;
		for(int j = 0; j < k; ++j){
			int temp;
			cin>>temp;
			tree[id].child.push_back(temp);
		}
	}
	int level[maxn] = {0}, level_max = 0;
	queue<int> q;
	q.push(1);
	tree[1].level = 1;
	while(!q.empty()){
		int now = q.front();
		q.pop();
		if(tree[now].isNo_leaf) level[tree[now].level]++;
		if(tree[now].level > level_max) level_max = tree[now].level;
		for(int j = 0; j < tree[now].child.size(); ++j){
			int child = tree[now].child[j];
			q.push(child);
			tree[child].level = tree[now].level + 1;
		}
	}
	for(int i = 1; i <= level_max; ++i){
		if(i != 1) cout<<" ";
		cout<<level[i];
	}
	cout<<endl;
	
	return 0;
}
