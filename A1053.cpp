//2019.2.16 14:57
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
const int maxn = 105;
struct Tree{
	int weight, id;
	bool isLeaf, tag;//tag is for DFS
	vector<int> child;
}tree[maxn];
bool cmp(int a, int b){
	return tree[a].weight > tree[b].weight;
}
vector<int> dfs;
void print(vector<int> d){
	for(int i = 0; i < d.size(); ++i){
		if(i) cout<<" ";
		cout<<d[i];
	}
	cout<<endl;
}
void DFS(int i, int weight){
	dfs.push_back(tree[i].weight);
	weight -= tree[i].weight;
	if(weight == 0 && tree[i].isLeaf) print(dfs);
	for(int j = 0; j < tree[i].child.size(); ++j){
		int temp = tree[i].child[j];
		DFS(temp, weight);
	}
	vector<int>::iterator it = dfs.end();
	it--;
	dfs.erase(it);
}
int main(){
	int n, m, s;
	cin>>n>>m>>s;
	for(int i = 0; i < n; ++i){
		int weight;
		cin>>weight;
		tree[i].weight = weight;
		tree[i].isLeaf = true;
		tree[i].tag = false;
		tree[i].id = i;
	}
		
	for(int i = 0; i < m; ++i){
		int now, k;
		cin>>now>>k;
		for(int j = 0; j < k; ++j){
			int child;
			cin>>child;
			tree[now].child.push_back(child);
			tree[now].isLeaf = false;
		}
		sort(tree[now].child.begin(), tree[now].child.end(), cmp);
	}
	DFS(0, s);
	return 0;
}
