//2019/3/5 19:45
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn = 205;
bool G[maxn][maxn] = {false};
bool vis[maxn] = {false};
int main(){
	int n, m, k;
	scanf("%d %d", &n, &m);
	fill(G[0], G[0] + maxn * maxn, false);
	for(int i = 0; i < m; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		G[u][v] = G[v][u] = true;
	}
	scanf("%d", &k);
	for(int i = 0; i < k; ++i){
		fill(vis, vis + n + 1, false);
		int node, pre, now, root;
		scanf("%d", &node);
		bool flag = true;
		scanf("%d", &root);
		pre = root;
		for(int j = 1; j < node; ++j){
			scanf("%d", &now);
			if(vis[now] == false) vis[now] = true;
			else flag = false;
			if(flag && G[pre][now] == false) flag = false;
			pre = now;		
		}
		if(now != root) flag = false;
		if(flag)
			for(int j = 1; j <= n; ++j)
				if(vis[j] == false) flag = false;
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
