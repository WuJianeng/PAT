//2019 4/30 11:54
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 205;
vector<int> node[maxn];
vector<int> data;
void verify(int n){
	int vis[maxn];
	fill(vis, vis + maxn, 0);
	for(int i = 0; i < data.size(); ++i){
		int u = data[i];
		int len = node[u].size();
		for(int j = 0; j < len; ++j){
			int v = node[u][j];
			vis[v]++;
		}
	}
	for(int i = 0; i< data.size(); ++i){
		int u = data[i];
		if(vis[u] < data.size() - 1){
			printf("Not a Clique\n");
			return ;
		}
	}
	for(int i = 0; i < data.size(); ++i){
		int u = data[i];
		vis[u] = 0;
	}
	for(int i = 1; i <= n; ++i){
		if(vis[i] == data.size()){
			printf("Not Maximal\n");
			return ;
		}
	}
	printf("Yes\n");
	return ;
}
int main(){
	int n, e;
	scanf("%d %d", &n, &e);
	for(int i = 0; i < e; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		node[u].push_back(v);
		node[v].push_back(u);
	}
	int m, k;
	scanf("%d", &m);
	for(int j = 0; j < m; ++j){
		data.clear();
		scanf("%d", &k);
		for(int i = 0; i < k; ++i){
			int temp;
			scanf("%d", &temp);
			data.push_back(temp);
		}
		verify(n);
	}
	return 0;
}
