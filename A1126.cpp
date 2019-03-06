//2019/3/6 15:32
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 505;
vector< vector<int> > v;
vector<bool> vis;
int cnt = 0;
void dfs(int root){
	if(vis[root] == true) return ;
	cnt++;
	vis[root] = true;
	for(int i = 0; i < v[root].size(); ++i)
		dfs(v[root][i]);
}

int main(){
	int n, m , even = 0;
	cin>>n>>m;
	v.resize(n + 1);
	vis.resize(n + 1);
	for(int i = 0; i < m; ++i){
		int st, ed;
		cin>>st>>ed;
		v[st].push_back(ed);
		v[ed].push_back(st);
	}
	for(int i = 1; i <= n; ++i){
		if(i != 1) cout<<" ";
		cout<<v[i].size();
		if(v[i].size() % 2 == 0) even++;
	}
	cout<<endl;
	fill(vis.begin(), vis.end(), false);
	dfs(1);
	if(cnt == n && even == n)
		cout<<"Eulerian"<<endl;
	else if(cnt == n && even == n - 2)
		cout<<"Semi-Eulerian"<<endl;
	else cout<<"Non-Eulerian"<<endl;
	return 0;
}
