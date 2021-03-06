//2019.2.17 14:30 forked from LiuChuo github
#include<iostream>
#include<map>
#include<string>
using namespace std;
map<string, int> stringToInt;
map<int, string> intToString;
map<string, int> ans;
int idNumber = 1, k;
int transfer(string s){
	if(stringToInt[s] == 0){
		stringToInt[s] = idNumber;
		intToString[idNumber] = s;
		return idNumber++;
	}
	else return stringToInt[s];
}
int G[2010][2010], weight[2010];
bool vis[2010];
void dfs(int u, int &head, int &numMember, int &totalWeight){
	vis[u] = true;
	numMember++;
	if(weight[u] > weight[head]) head = u;
	for(int v = 1; v < idNumber; ++v){
		if(G[u][v] > 0){
			totalWeight += G[u][v];
			G[u][v] = G[v][u] = 0;
			if(vis[v] == false) 
				dfs(v, head, numMember, totalWeight);
		}
	}
}
void dfsTrave(){
	for(int i = 1; i < idNumber; ++i){
		if(vis[i] == false){
			int head = i, numMember = 0, totalWeight = 0;
			dfs(i, head, numMember, totalWeight);
			if(numMember > 2 && totalWeight > k)
				ans[intToString[head]] = numMember;
		}
	}
}
int main(){
	int n, w;
	cin>>n>>k;
	string s1, s2;
	for(int i = 1; i <= n; ++i){
		cin>>s1>>s2>>w;
		int id1 = transfer(s1);
		int id2 = transfer(s2);
		weight[id1] += w;
		weight[id2] += w;
		G[id1][id2] += w;
		G[id2][id1] += w;		
	}
	dfsTrave();
	cout<<ans.size()<<endl;
	for(map<string, int>::iterator it = ans.begin(); it != ans.end(); ++it)
		cout<< it->first << " " << it->second << endl;
	return 0;
}
