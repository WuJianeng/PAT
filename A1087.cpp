//2019/2/25 12:15
#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
const int maxn = 205, INF = 1000000000;
int n, k;
map<string, int> stringToInt;
map<int, string> intToString;
vector<int> weight, pre[maxn], path, tempPath;
int G[maxn][maxn], d[maxn];
bool vis[maxn] = {false};

void Dijkstra(int s){
	fill(d, d + maxn, INF);
	d[s] = 0;
	for(int i = 0; i < n; ++i){
		int u = -1, Min = INF;
		for(int j = 0; j < n; ++j){
			if(vis[j] == false && d[j] < Min){
				u = j;
				Min = d[j];
			}
		}
		if(u == -1) return ;
		vis[u] = true;
		for(int v = 0; v < n; ++v){
			if(vis[v] == 0 && d[u] + G[u][v] < d[v]){
				d[v] = d[u] + G[u][v];
				pre[v].clear();
				pre[v].push_back(u);
			}
			else if(vis[v] == 0 && d[u] + G[u][v] == d[v]){
				pre[v].push_back(u);
			}
		}
	}
}
int routes = 0, minCost = INF, maxHap = 0, aveHap = 0;
void DFS(int s){
	if(s == 0){
		int cost = 0, hap = 0;
		int preNode = 0;
		for(int i = tempPath.size() - 1; i >= 0; --i){
			int node = tempPath[i];
			hap += weight[node];
			cost += G[preNode][node];
			preNode = node;
		}
		tempPath.push_back(0);
		if(cost < minCost){
			minCost = cost;
			routes = 1;
			maxHap = hap;
			aveHap = hap / (tempPath.size() - 1);
			path = tempPath;
		}
		else if(cost == minCost){
			routes++;
			if(hap > maxHap){
				maxHap = hap;
				aveHap = hap / (tempPath.size()- 1 );
				path = tempPath;
			}
			else if(hap == maxHap && hap / (tempPath.size() - 1) > maxHap){
				maxHap = hap / (tempPath.size() - 1);
				path = tempPath;
			}
		}
		tempPath.pop_back();
		return ;
	}
	tempPath.push_back(s);
	for(int i = 0; i < pre[s].size(); ++i){
		DFS(pre[s][i]);
	}
	tempPath.pop_back();
}
void print(string str){
	cout<<routes<<" "<<minCost<<" "<<maxHap<<" "<<aveHap<<endl;
	for(int i = path.size() - 1; i >= 0; --i){
		cout<<intToString[path[i]];
		if(i != 0) cout<<"->";
	}
	cout<<endl;
}
int main(){
	cin>>n>>k;
	string str;
	cin>>str;
	stringToInt[str] = 0;
	intToString[0] = str;
	weight.push_back(0);
	for(int i = 1; i < n; ++i){
		string s;
		int w;
		cin>>s>>w;
		stringToInt[s] = i;
		intToString[i] = s;
		weight.push_back(w);
	}
	fill(G[0], G[0] + maxn * maxn, INF);
	for(int i = 0; i < k; ++i){
		string fir, sec;
		cin>>fir>>sec;
		int u = stringToInt[fir];
		int v = stringToInt[sec];
		cin>>G[u][v];
		G[v][u] = G[u][v];
	}
	Dijkstra(0);
	DFS(stringToInt["ROM"]);
	print(str);
	return 0;
}
