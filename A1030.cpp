//2019/2/24 19:52 forked from QingShen Notes;
#include<cstdio>
#include<algorithm>
using namespace std;
#define max  505
const int INF = 1000000000;

int n, m, st, ed, G[max][max], cost[max][max];
int d[max], c[max], pre[max];
bool vis[max] = {false};
void dijkstra(int s){
	fill(d, d + max, INF);
	fill(c, c + max, INF);
	for(int i = 0; i < n; ++i)
		pre[i] = i;
	d[s] = 0;
	c[s] = 0;
	for(int i = 0; i < n; ++i){
		int u = -1, min = INF;
		for(int j = 0; j < n; ++j){
			if(vis[j] == false && d[j] < min){
				u = j;
				min = d[j];
			}
		}
		if(u == -1) return ;
		vis[u] = true;
		for(int v = 0; v < n; ++v){
			if(vis[v] == false && G[u][v] != INF){
				if(G[u][v] + d[u] < d[v]){
					d[v] = G[u][v] + d[u];
					pre[v] = u;
					c[v] = c[u] + cost[u][v]; 
				} 
				else if(G[u][v] + d[u] == d[v] && c[u] + cost[u][v] < c[v]){
					c[v] = c[u] + cost[u][v];
					pre[v] = u;
				}
			}	
		} 
	}
}
void print(int v){
	if(v == st){
		printf("%d ",v);
		return ;
	}
	print(pre[v]);
	printf("%d ", v);
}
int main(){
	scanf("%d %d %d %d", &n, &m, &st, &ed);
	fill(G[0], G[0] + max * max, INF);
	for(int i = 0; i < m; i++){
		int start, end, dis, cos;
		scanf("%d %d %d %d", &start, &end, &dis, &cos);
		G[start][end] = dis;
		G[end][start] = dis;
		cost[start][end] = cos;
		cost[end][start] = cos;
	}
	dijkstra(st);
	print(ed);
	printf("%d %d\n", d[ed], c[ed]);
	return 0;
} 
