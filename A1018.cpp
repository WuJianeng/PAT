//2019/2/24 22:50
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
const int INF = 100000000;
int cap, staNum, proPla, roadNum;
int sto[505], G[505][505], d[505];
bool vis[505] = {false};
vector<int> pre[505];
vector<int> tempPath, path;
void Dijkstra(int s){
	fill(d, d + 505, INF);
	d[s] = 0;
	for(int i = 0; i <= staNum; ++i){
		int u = -1, min = INF;
		for(int j = 0; j <= staNum; ++j){
			if(vis[j] == false && d[j] < min){
				min = d[j];
				u = j;
			}
		}
		if(u == -1) return ;
		vis[u] = true;
		for(int v = 0; v <= staNum; ++v){
			if(vis[v] == false && d[u] + G[u][v] < d[v]){
				d[v] = d[u] + G[u][v];
				pre[v].clear();
				pre[v].push_back(u);
			}
			else if(vis[v] == false && d[u] + G[u][v] == d[v])
				pre[v].push_back(u);
		}
	}
}
int minNeed = INF, minRemain = INF;
void DFS(int s){
	if(s == 0){
		tempPath.push_back(s);
		int need = 0, remain = 0;
		for(int i = tempPath.size() - 1; i >= 0; --i){
			int id = tempPath[i];
			if(sto[id] > 0)
				remain += sto[id];
			else if(sto[id] < 0 && remain > abs(sto[id]))
				remain -= abs(sto[id]);
			else if(sto[id] < 0 && remain < abs(sto[id])){
				need += abs(sto[id]) - remain;
				remain = 0;
			}
		}
		if(need < minNeed){
			path = tempPath;
			minNeed = need;
			minRemain = remain;
		}
		else if(need == minNeed && remain < minRemain){
			path = tempPath;
			minRemain = remain;
		}
		tempPath.pop_back();
		return ;
	}
	tempPath.push_back(s);
	for(int i = 0; i < pre[s].size(); ++i)
		DFS(pre[s][i]);
	tempPath.pop_back();
}
void print(){
	cout<<minNeed<<" ";
	for(int i = path.size() - 1; i >= 0; --i){
		cout<<path[i];
		if(i != 0) cout<<"->";
	}
	cout<<" "<<minRemain<<endl;
}
int main(){
	cin>>cap>>staNum>>proPla>>roadNum;
	for(int i = 1; i <= staNum; ++i){
		int temp;
		cin>>temp;
		sto[i] = temp - cap / 2;
	}
	fill(G[0], G[0] + 505 * 505, INF);
	for(int i = 0; i < roadNum; ++i){
		int st, end, w;
		cin>>st>>end>>w;
		G[st][end] = w;
		G[end][st] = w;
	}
	Dijkstra(0);
	DFS(proPla);
	print();
	return 0;
}
