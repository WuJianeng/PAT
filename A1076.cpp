//2019.2.17 15:05
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> G[1010];
bool vis[1010];
int le[1010];
void bfs(int query, int n, int level){
	for(int i = 1; i <= n; ++i)
			vis[i] = false;
	queue<int> q;
	q.push(query);
	le[query] = 0;
	int numMember = 0;
	vis[query] = true;
	while(!q.empty()){
		int now = q.front();
		q.pop();
		numMember++;
		if(le[now] < level)
			for(int j = 0; j < G[now].size(); ++j){
				int v = G[now][j];
				if(vis[v] == false){
					q.push(v);
					le[v] = le[now] + 1;
					vis[v] = true;	
				}
					
		}
	}
	cout<<numMember - 1<<endl;
}
int main(){
	int n, level, k;
	cin>>n>>level;
	for(int u = 1; u <= n; ++u){
		int num;
		cin>>num;
		if(num)
		for(int j = 0; j < num; ++j){
			int v;
			cin>>v;
			G[v].push_back(u);
		}
	}
	cin>>k;
	for(int i = 0; i < k; ++i){
		int query;
		cin>>query;
		bfs(query, n, level);
	}
	return 0;
}
